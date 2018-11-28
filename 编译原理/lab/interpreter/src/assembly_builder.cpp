
#include "assembly_builder.h"
#include <iostream>
#include <vector>
//用于输出错误的宏
#define Error(explanation)                           \
    {                                                \
        error_flag = true;                           \
        err.error(node.line, node.pos, explanation); \
        return;                                      \
    }
#define N 1

using namespace std;
using namespace llvm;
using namespace c1_recognizer::syntax_tree;

void assembly_builder::visit(assembly &node) {
    auto list = node.global_defs;
    bb_count = 0;
    int i;
    lval_as_rval = false;
    for (i = 0; i < list.size(); i++) {
        in_global = true;
        list[i]->accept(*this);
    }
}

void assembly_builder::visit(func_def_syntax &node) {
    in_global = false;
    if (functions.count(node.name)) {
        Error("Function '" + node.name + "' multiply defined. Skipping.");
    }
    auto func_type = FunctionType::get(Type::getVoidTy(context), std::vector<Type *>(), false);
    auto func = Function::Create(func_type, GlobalValue::LinkageTypes::ExternalLinkage, node.name,
                                 module.get());
    auto entry = BasicBlock::Create(context, "entry", func);
    current_function = func;
    builder.SetInsertPoint(entry);
    node.body->accept(*this);
    builder.CreateRetVoid();
    functions.insert(pair<string, llvm::Function *>(node.name, func));
    builder.ClearInsertionPoint();
}

void assembly_builder::visit(cond_syntax &node) {
    node.lhs->accept(*this);
    auto leftvalue = value_result;
    auto leftflag = is_result_int;  //根据读取结果的判断是否为整数把结果记录下来

    auto leftnum = leftflag ? int_const_result : float_const_result;
    node.rhs->accept(*this);
    auto rightvalue = value_result;
    auto rightflag = is_result_int;
    auto rightnum = rightflag ? int_const_result : float_const_result;
    auto isint = leftflag && rightflag;
    auto leftresult =
        leftvalue
            ? (isint ? leftvalue
                     : (leftflag ? builder.CreateSIToFP(value_result, Type::getDoubleTy(context))
                                 : leftvalue))
            : (isint ? ConstantInt::get(Type::getInt32Ty(context), leftnum)
                     : ConstantFP::get(Type::getDoubleTy(context), leftnum));

    auto rightresult =
        rightvalue
            ? (isint ? rightvalue
                     : (rightflag ? builder.CreateSIToFP(value_result, Type::getDoubleTy(context))
                                  : rightvalue))
            : (isint ? ConstantInt::get(Type::getInt32Ty(context), rightnum)
                     : ConstantFP::get(Type::getDoubleTy(context), rightnum));
    switch (node.op) {
        case relop::equal:
            if (isint) {
                value_result = builder.CreateICmpEQ(leftresult, rightresult);
            } else {
                Error("Cannot judge equal between DoubleType.");
            }

            break;
        case relop::non_equal:
            if (isint) {
                value_result = builder.CreateICmpNE(leftresult, rightresult);
            } else {
                Error("Cannot judge notequal between DoubleType.");
            }
            break;
        case relop::less:
            value_result = isint ? builder.CreateICmpSLT(leftresult, rightresult)
                                 : builder.CreateFCmpOLT(leftresult, rightresult);
            break;
        case relop::less_equal:
            value_result = isint ? builder.CreateICmpSLE(leftresult, rightresult)
                                 : builder.CreateFCmpOLE(leftresult, rightresult);
            break;
        case relop::greater:
            value_result = isint ? builder.CreateICmpSGT(leftresult, rightresult)
                                 : builder.CreateFCmpOGT(leftresult, rightresult);
            break;
        case relop::greater_equal:
            value_result = isint ? builder.CreateICmpSGE(leftresult, rightresult)
                                 : builder.CreateFCmpOGE(leftresult, rightresult);
            break;
    }
}

void assembly_builder::visit(binop_expr_syntax &node) {
    node.lhs->accept(*this);
    auto leftvalue = value_result;
    auto leftflag = is_result_int;  //根据读取结果的判断是否为整数把结果记录下来
    auto leftnum = leftflag ? int_const_result : float_const_result;
    node.rhs->accept(*this);
    auto rightvalue = value_result;
    auto rightflag = is_result_int;
    auto rightnum = rightflag ? int_const_result : float_const_result;
    auto isint = leftflag && rightflag;
    is_result_int = isint;
    if (!leftvalue && !rightvalue) {  //两边得到的都是常数
        if (!isint) {  //两者中有一个为浮点数时进行类型转换，整体以浮点数计算
            double left = (double)leftnum, right = (double)rightnum;
            is_result_int = false;
            switch (node.op) {
                case binop::plus:
                    float_const_result = left + right;
                    break;
                case binop::minus:
                    float_const_result = left - right;
                    break;
                case binop::multiply:
                    float_const_result = left * right;
                    break;
                case binop::divide:
                    float_const_result = left / right;
                    break;
                case binop::modulo:
                    float_const_result = 0;
                default:
                    break;
            }
        } else {  //否则就是整型计算
            int left = leftnum, right = rightnum;
            is_result_int = true;
            switch (node.op) {
                case binop::plus:
                    int_const_result = left + right;
                    break;
                case binop::minus:
                    int_const_result = left - right;
                    break;
                case binop::multiply:
                    int_const_result = left * right;
                    break;
                case binop::divide:
                    int_const_result = left / right;
                    break;
                case binop::modulo:
                    int_const_result = left % right;
                    break;
                default:
                    break;
            }
        }
    } else {  //两边中有一个以上是变量
        auto leftresult =
            leftvalue
                ? (isint ? leftvalue
                         : (leftflag ? builder.CreateSIToFP(leftvalue, Type::getDoubleTy(context))
                                     : leftvalue))
                : (isint ? ConstantInt::get(Type::getInt32Ty(context), leftnum)
                         : ConstantFP::get(Type::getDoubleTy(context), leftnum));

        auto rightresult =
            rightvalue
                ? (isint ? rightvalue
                         : (rightflag ? builder.CreateSIToFP(rightvalue, Type::getDoubleTy(context))
                                      : rightvalue))
                : (isint ? ConstantInt::get(Type::getInt32Ty(context), rightnum)
                         : ConstantFP::get(Type::getDoubleTy(context), rightnum));

        switch (node.op) {
            case binop::plus:
                value_result = isint ? builder.CreateAdd(leftresult, rightresult)
                                     : builder.CreateFAdd(leftresult, rightresult);
                break;
            case binop::minus:
                value_result = isint ? builder.CreateSub(leftresult, rightresult)
                                     : builder.CreateFSub(leftresult, rightresult);
                break;
            case binop::multiply:
                value_result = isint ? builder.CreateMul(leftresult, rightresult)
                                     : builder.CreateFMul(leftresult, rightresult);
                break;
            case binop::divide:
                value_result = isint ? builder.CreateExactSDiv(leftresult, rightresult)
                                     : builder.CreateFDiv(leftresult, rightresult);
                break;
            case binop::modulo:
                value_result = isint ? builder.CreateSRem(leftresult, rightresult)
                                     : builder.CreateFRem(leftresult, rightresult);
                break;
        }
    }
}

void assembly_builder::visit(unaryop_expr_syntax &node) {
    node.rhs->accept(*this);
    if (constexpr_expected) {  //是常量
        if (is_result_int) {   //是整数且前面为负号则变为负
            if (node.op == unaryop::minus) int_const_result = -int_const_result;
            is_result_int = true;
        } else {
            if (node.op == unaryop::minus) float_const_result = -float_const_result;
            is_result_int = false;
        }
    } else {  //是变量
        auto var = value_result;
        if (is_result_int) {
            if (node.op == unaryop::minus) {
                auto zero = ConstantInt::get(Type::getInt32Ty(context), 0);
                value_result = builder.CreateSub(zero, var);
            }
        } else {
            if (node.op == unaryop::minus) {
                auto zero = ConstantFP::get(Type::getDoubleTy(context), 0);
                value_result = builder.CreateFSub(zero, var);
            }
        }
    }
}

void assembly_builder::visit(lval_syntax &node) {
    //变量四元组：地址，是否常量，是否数组，是否int
    auto var = lookup_variable(node.name);
    if (get<0>(var) == NULL) {
        Error("Use of undeclared variable '" + node.name + "'.");
    }
    is_result_int = get<3>(var);
    if (lval_as_rval) {            //左值
        if (constexpr_expected) {  //此时应是常量
            Error("Constant expression expected.");
        }
        if (get<1>(var)) {  //对常量赋值
            Error("Assigning to constant.");
        }
        if (get<2>(var)) {  //是数组
            constexpr_expected = true;
            node.array_index->accept(*this);
            auto index = int_const_result;
            constexpr_expected = false;
            Value *idexlist[2] = {ConstantInt::get(Type::getInt32Ty(context), 0),
                                  ConstantInt::get(Type::getInt32Ty(context), index)};
            value_result = builder.CreateGEP(get<0>(var), idexlist);

        } else  //不是数组
            value_result = get<0>(var);
    } else {  //右值
        // constexpr_expected = false;
        if (get<2>(var)) {  //是数组
            constexpr_expected = true;
            node.array_index->accept(*this);
            auto index = int_const_result;
            constexpr_expected = false;
            Value *idexlist[2] = {ConstantInt::get(Type::getInt32Ty(context), 0),
                                  ConstantInt::get(Type::getInt32Ty(context), index)};
            auto tmpvaraddr = builder.CreateGEP(get<0>(var), idexlist);

            value_result = builder.CreateLoad(tmpvaraddr);
        } else
            value_result = builder.CreateLoad(get<0>(var));
    }
    is_result_int = get<3>(var);
}

void assembly_builder::visit(literal_syntax &node) {
    //数字始终认为是常量，直接把结果存进去
    value_result = NULL;
    if (node.is_int) {
        int_const_result = node.intConst;
        // cout << "literal:" << int_const_result << endl;
        is_result_int = true;
    } else {
        // cout << "literal:" << float_const_result << endl;
        float_const_result = node.floatConst;
        is_result_int = false;
    }
    auto num = is_result_int ? int_const_result : float_const_result;
    // cout<<"literal "<<num<<endl;
}

void assembly_builder::visit(var_def_stmt_syntax &node) {
    //变量四元组：地址，是否常量，是否数组，是否int
    bool declare_flag = true;
    if (in_global) {  //全局变量
        constexpr_expected = true;
        if (node.array_length == NULL) {  //非数组
            if (node.initializers.size() > 0) {
                node.initializers[0]->accept(*this);
            } else {
                int_const_result = 0;
                float_const_result = 0;
            }
            auto type = node.is_int ? Type::getInt32Ty(context) : Type::getDoubleTy(context);
            auto numget = is_result_int ? int_const_result : float_const_result;
            auto num = node.is_int ? (int)numget : (double)numget;
            auto data = node.is_int ? ConstantInt::get(Type::getInt32Ty(context), num)
                                    : ConstantFP::get(Type::getDoubleTy(context), num);
            // numget是读取到的数，num是将其根据左边的值做了类型转换的值
            auto gvar = new GlobalVariable(*module.get(), type, node.is_constant,
                                           GlobalValue::ExternalLinkage, data);
            declare_flag = declare_variable(node.name, gvar, node.is_constant, false, node.is_int);
        } else {  //数组
            node.array_length->accept(*this);
            auto length = int_const_result;
            if (!is_result_int) {
                Error("Array length type not properly set.");
            }
            if (length < node.initializers.size()) {
                Error("Too much initializer expressions.");
            }
            auto type = node.is_int ? Type::getInt32Ty(context) : Type::getDoubleTy(context);
            auto arraytype = ArrayType::get(Type::getInt32Ty(context), length);

            std::vector<llvm::Constant *> list;
            auto one = ConstantInt::get(type, 1);
            for (int i = 0; i < length; i++) {
                if (i < node.initializers.size()) {
                    node.initializers[i]->accept(*this);
                    auto numget = is_result_int ? int_const_result : float_const_result;
                    auto num = node.is_int ? (int)numget : (double)numget;
                    auto data =
                        node.is_int ? ConstantInt::get(type, num) : ConstantFP::get(type, num);
                    list.push_back(data);
                } else {
                    auto data = node.is_int ? ConstantInt::get(type, 0) : ConstantFP::get(type, 0);
                    list.push_back(data);
                }
            }
            auto array = ConstantArray::get(arraytype, list);
            auto gvar = new GlobalVariable(*module.get(), arraytype, node.is_constant,
                                           GlobalValue::ExternalLinkage, array);
        }

    } else {
        if (node.is_int) {                    //整数部分
            if (node.array_length == NULL) {  //不是数组
                auto var = builder.CreateAlloca(Type::getInt32Ty(context), nullptr);
                if (node.is_constant) {
                    declare_flag = declare_variable(node.name, var, true, false, true);
                } else
                    declare_flag = declare_variable(node.name, var, false, false, true);

                if (node.initializers.size() > 0) {
                    node.initializers[0]->accept(*this);
                    auto numget = is_result_int ? int_const_result : float_const_result;
                    int_const_result = (int)numget;
                } else
                    int_const_result = 0;
                auto num = ConstantInt::get(Type::getInt32Ty(context), int_const_result);
                if (value_result) {
                    value_result = is_result_int ? value_result
                                                 : builder.CreateFPToSI(value_result,
                                                                        Type::getInt32Ty(context));
                    builder.CreateStore(value_result, var);
                }

                else
                    builder.CreateStore(num, var);
            } else {  //是数组
                constexpr_expected = true;
                node.array_length->accept(*this);
                if (!is_result_int) {
                    Error("Array length type not properly set.");
                }
                auto length = int_const_result;
                if (length < node.initializers.size()) {
                    Error("Too much initializer expressions.");
                }
                auto type = IntegerType::getInt32Ty(context);
                auto arraytype = ArrayType::get(type, length);
                auto var = builder.CreateAlloca(arraytype, nullptr);
                if (node.is_constant) {
                    declare_flag = declare_variable(node.name, var, true, true, true);
                } else
                    declare_flag = declare_variable(node.name, var, false, true, true);
                int i;
                for (i = 0; i < length; i++) {
                    Value *idex[2] = {ConstantInt::get(Type::getInt32Ty(context), 0),
                                      ConstantInt::get(Type::getInt32Ty(context), i)};
                    if (i < node.initializers.size()) {
                        node.initializers[i]->accept(*this);
                        if (!is_result_int) int_const_result = (int)float_const_result;  //类型转换
                    } else
                        int_const_result = 0;
                    if (value_result) {
                        value_result = is_result_int ? value_result
                                                     : builder.CreateFPToSI(
                                                           value_result, Type::getInt32Ty(context));
                    }
                    auto num =
                        value_result
                            ? value_result
                            : (ConstantInt::get(Type::getInt32Ty(context), int_const_result));
                    auto tmpvar = builder.CreateGEP(var, idex);
                    builder.CreateStore(num, tmpvar);
                }
            }

        } else {                              //浮点数部分
            if (node.array_length == NULL) {  //不是数组
                auto var = builder.CreateAlloca(Type::getDoubleTy(context), nullptr);
                if (node.is_constant) {  //是常量
                    declare_flag = declare_variable(node.name, var, true, false, false);
                } else
                    declare_flag = declare_variable(node.name, var, false, false, false);
                if (node.initializers.size() > 0) {
                    node.initializers[0]->accept(*this);
                    if (is_result_int) float_const_result = (double)int_const_result;
                } else
                    float_const_result = 0;
                auto num = ConstantFP::get(Type::getDoubleTy(context), float_const_result);
                if (value_result) {
                    value_result = !is_result_int ? value_result
                                                  : builder.CreateFPToSI(
                                                        value_result, Type::getDoubleTy(context));
                    builder.CreateStore(value_result, var);
                } else
                    builder.CreateStore(num, var);
            } else {  //是数组
                constexpr_expected = true;
                node.array_length->accept(*this);
                if (!is_result_int) {
                    Error("Array length type not properly set.");
                }
                auto length = int_const_result;
                if (length < node.initializers.size()) {
                    Error("Too much initializer expressions.");
                }
                auto type = IntegerType::getDoubleTy(context);
                auto arraytype = ArrayType::get(type, length);
                auto var = builder.CreateAlloca(arraytype, nullptr);
                if (node.is_constant) {
                    declare_flag = declare_variable(node.name, var, true, true, false);
                } else
                    declare_flag = declare_variable(node.name, var, false, true, false);
                int i;
                for (i = 0; i < length; i++) {
                    Value *idex[2] = {ConstantInt::get(Type::getInt32Ty(context), 0),
                                      ConstantInt::get(Type::getInt32Ty(context), i)};
                    if (i < node.initializers.size()) {
                        node.initializers[i]->accept(*this);
                        if (is_result_int) float_const_result = (double)int_const_result;
                    }

                    else
                        float_const_result = 0;
                    if (value_result) {
                        value_result =
                            !is_result_int
                                ? value_result
                                : builder.CreateSIToFP(value_result, Type::getDoubleTy(context));
                    }
                    auto num =
                        value_result
                            ? value_result
                            : (ConstantFP::get(Type::getDoubleTy(context), float_const_result));
                    auto tmpvar = builder.CreateGEP(var, idex);
                    builder.CreateStore(num, tmpvar);
                }
            }
        }
    }

    if (!declare_flag) {
        Error("Multiple declaration of variable '" + node.name + "' in current scope.");
    }
    constexpr_expected = false;
}

void assembly_builder::visit(assign_stmt_syntax &node) {
    lval_as_rval = true;
    constexpr_expected = false;
    node.target->accept(*this);  //取得左值的地址
    lval_as_rval = false;
    auto var = value_result;
    auto targetflag = is_result_int;
    node.value->accept(*this);
    auto is_value_int = is_result_int;
    auto result = is_result_int ? int_const_result : float_const_result;
    if (value_result) {
        if (targetflag && !is_value_int)
            value_result = builder.CreateFPToSI(value_result, Type::getInt32Ty(context));
        if (!targetflag && is_value_int)
            value_result = builder.CreateSIToFP(value_result, Type::getDoubleTy(context));
        builder.CreateStore(value_result, var);
    }

    else {
        auto num = targetflag ? ConstantInt::get(Type::getInt32Ty(context), result)
                              : ConstantFP::get(Type::getDoubleTy(context), result);
        builder.CreateStore(num, var);
    }
}

void assembly_builder::visit(func_call_stmt_syntax &node) {
    auto func = functions[node.name];
    if (func == NULL) {
        error_flag = true;
        string error = "Called function not defined: '" + node.name + "'.";
        err.error(node.line, node.pos, error);

    } else {
        builder.CreateCall(func, {});
    }
}

void assembly_builder::visit(block_syntax &node) {
    auto list = node.body;
    enter_scope();
    for (int i = 0; i < list.size(); i++) {
        list[i]->accept(*this);
    }
    exit_scope();
    // cout << "block end" << endl;
}

void assembly_builder::visit(if_stmt_syntax &node) {
    // if语句块
    auto IfB = BasicBlock::Create(context, "IfB", current_function);
    builder.CreateBr(IfB);
    builder.SetInsertPoint(IfB);
    node.pred->accept(*this);
    auto cond = value_result;
    auto ThenB = BasicBlock::Create(context, "ThenB", current_function);
    BasicBlock *ElseB;
    if (node.else_body) {  //判断有没有else，有则插入
        ElseB = BasicBlock::Create(context, "ElseB", current_function);
        builder.CreateCondBr(cond, ThenB, ElseB);
    }
    auto AfterIf = BasicBlock::Create(context, "AfterIf", current_function);

    if (!node.else_body)  //否则条件为假时直接跳到afterif
        builder.CreateCondBr(cond, ThenB, AfterIf);
    builder.SetInsertPoint(ThenB);
    node.then_body->accept(*this);
    builder.CreateBr(AfterIf);
    if (node.else_body) {
        builder.SetInsertPoint(ElseB);
        node.else_body->accept(*this);
        builder.CreateBr(AfterIf);
    }

    builder.SetInsertPoint(AfterIf);
}

void assembly_builder::visit(while_stmt_syntax &node) {
    auto WhileB = BasicBlock::Create(context, "WhileB" + to_string(bb_count++), current_function);
    builder.CreateBr(WhileB);
    builder.SetInsertPoint(WhileB);
    node.pred->accept(*this);
    auto cond = value_result;
    auto BodyB = BasicBlock::Create(context, "BodyB" + to_string(bb_count++), current_function);
    auto AfterB = BasicBlock::Create(context, "AfterB" + to_string(bb_count++), current_function);

    builder.CreateCondBr(cond, BodyB, AfterB);
    builder.SetInsertPoint(BodyB);
    node.body->accept(*this);
    builder.CreateBr(WhileB);
    builder.SetInsertPoint(AfterB);
}

void assembly_builder::visit(empty_stmt_syntax &node) {}
