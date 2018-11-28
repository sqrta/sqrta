
#include "syntax_tree_builder.h"
#include <iostream>
#include <memory>
#include <typeinfo>

using namespace std;
using namespace c1_recognizer;
using namespace c1_recognizer::syntax_tree;

syntax_tree_builder::syntax_tree_builder(error_reporter &_err) : err(_err) {}

antlrcpp::Any syntax_tree_builder::visitCompilationUnit(C1Parser::CompilationUnitContext *ctx) {
    auto result = new assembly;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    if (ctx->compilationUnit()) {
        auto tmp_result = visit(ctx->compilationUnit()).as<assembly *>();
        for (int i = 0; i < tmp_result->global_defs.size(); i++)
            result->global_defs.push_back(tmp_result->global_defs[i]);
    }
    if (ctx->funcdef()) {
        ptr<global_def_syntax> tmp;
        tmp.reset(visit(ctx->funcdef()).as<global_def_syntax *>());
        result->global_defs.push_back(tmp);
    } else if (ctx->decl()) {
        auto defs = visit(ctx->decl()).as<vector<var_def_stmt_syntax *>>();
        for (int j = 0; j < defs.size(); j++) {
            ptr<global_def_syntax> tmp;
            tmp.reset(defs[j]);
            result->global_defs.push_back(tmp);
        }
    }
    return static_cast<assembly *>(result);
}

antlrcpp::Any syntax_tree_builder::visitDecl(C1Parser::DeclContext *ctx) {
    if (ctx->constdecl()) {
        return visit(ctx->constdecl());
    } else
        return visit(ctx->vardecl());
}

antlrcpp::Any syntax_tree_builder::visitConstdecl(C1Parser::ConstdeclContext *ctx) {
    vector<var_def_stmt_syntax *> list;
    auto defs = ctx->constdef();
    for (int i = 0; i < defs.size(); i++) {
        auto tmp = visit(defs[i]).as<var_def_stmt_syntax *>();
        if (ctx->Int())
            tmp->is_int = true;
        else
            tmp->is_int = false;
        list.push_back(tmp);
    }

    return list;
}

antlrcpp::Any syntax_tree_builder::visitConstdef(C1Parser::ConstdefContext *ctx) {
    auto result = new var_def_stmt_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->name = ctx->Identifier()->getText();
    result->is_constant = true;
    auto exps = ctx->exp();
    if (ctx->LeftBracket()) {
        result->array_length.reset(visit(exps[0]).as<expr_syntax *>());
        for (int i = 1; i < exps.size(); i++) {
            ptr<expr_syntax> tmp;
            tmp.reset(visit(exps[i]).as<expr_syntax *>());
            result->initializers.push_back(tmp);
        }
    } else {
        ptr<expr_syntax> tmp;
        tmp.reset(visit(exps[0]).as<expr_syntax *>());
        result->initializers.push_back(tmp);
    }
    return static_cast<var_def_stmt_syntax *>(result);
}

antlrcpp::Any syntax_tree_builder::visitVardecl(C1Parser::VardeclContext *ctx) {
    vector<var_def_stmt_syntax *> list;
    auto defs = ctx->vardef();
    for (int i = 0; i < defs.size(); i++) {
        auto tmp = visit(defs[i]).as<var_def_stmt_syntax *>();
        if (ctx->Int())
            tmp->is_int = true;
        else
            tmp->is_int = false;
        list.push_back(tmp);
    }

    return list;
}

antlrcpp::Any syntax_tree_builder::visitVardef(C1Parser::VardefContext *ctx) {
    auto result = new var_def_stmt_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->name = ctx->Identifier()->getText();
    result->is_constant = false;
    auto exps = ctx->exp();
    if (ctx->LeftBracket()) {
        result->array_length.reset(visit(exps[0]).as<expr_syntax *>());
        for (int i = 1; i < exps.size(); i++) {
            ptr<expr_syntax> tmp;
            tmp.reset(visit(exps[i]).as<expr_syntax *>());
            result->initializers.push_back(tmp);
        }
    } else if (exps.size()) {
        ptr<expr_syntax> tmp;
        tmp.reset(visit(exps[0]).as<expr_syntax *>());
        result->initializers.push_back(tmp);
    }
    return static_cast<var_def_stmt_syntax *>(result);
}

antlrcpp::Any syntax_tree_builder::visitFuncdef(C1Parser::FuncdefContext *ctx) {
    auto result = new func_def_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->name = ctx->Identifier()->getText();
    result->body.reset(visit(ctx->block()).as<block_syntax *>());
    return static_cast<global_def_syntax *>(result);
}

antlrcpp::Any syntax_tree_builder::visitBlock(C1Parser::BlockContext *ctx) {
    auto result = new block_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    auto blockitems = ctx->blockitem();
    for (int i = 0; i < blockitems.size(); i++) {
        if (blockitems[i]->stmt()) {
            ptr<stmt_syntax> tmp;
            tmp.reset(visit(blockitems[i]->stmt()).as<stmt_syntax *>());
            result->body.push_back(tmp);
        }

        else {
            auto defs = visit(blockitems[i]->decl()).as<vector<var_def_stmt_syntax *>>();
            for (int j = 0; j < defs.size(); j++) {
                ptr<stmt_syntax> tmp;
                tmp.reset(defs[j]);
                result->body.push_back(tmp);
            }
        }
    }
    return static_cast<block_syntax *>(result);
}

antlrcpp::Any syntax_tree_builder::visitStmt(C1Parser::StmtContext *ctx) {
    auto stmts = ctx->stmt();
    if (ctx->Assign()) {
        auto result = new assign_stmt_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();

        result->target.reset(visit(ctx->lval()).as<lval_syntax *>());
        result->value.reset(visit(ctx->exp()).as<expr_syntax *>());
        return static_cast<stmt_syntax *>(result);
    }

    else if (ctx->Identifier()) {
        auto result = new func_call_stmt_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->name = ctx->Identifier()->getText();
        return static_cast<stmt_syntax *>(result);
    }

    else if (ctx->If()) {
        auto result = new if_stmt_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->pred.reset(visit(ctx->cond()).as<cond_syntax *>());
        result->then_body.reset(visit(stmts[0]).as<stmt_syntax *>());
        if (ctx->Else()) {
            result->else_body.reset(visit(stmts[1]).as<stmt_syntax *>());
        }
        return static_cast<stmt_syntax *>(result);
    }

    else if (ctx->While()) {
        auto result = new while_stmt_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->pred.reset(visit(ctx->cond()).as<cond_syntax *>());
        result->body.reset(visit(stmts[0]).as<stmt_syntax *>());
        return static_cast<stmt_syntax *>(result);
    }

    else if (ctx->SemiColon()) {
        auto result = new empty_stmt_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        return static_cast<stmt_syntax *>(result);
    }

    else if (ctx->block()) {
        return static_cast<stmt_syntax *>(visit(ctx->block()).as<block_syntax *>());
    }
}

antlrcpp::Any syntax_tree_builder::visitLval(C1Parser::LvalContext *ctx) {
    auto result = new lval_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->name = ctx->Identifier()->getText();
    if (ctx->exp())
        result->array_index.reset(visit(ctx->exp()).as<expr_syntax *>());
    else
        result->array_index.reset();
    return static_cast<lval_syntax *>(result);
}

antlrcpp::Any syntax_tree_builder::visitCond(C1Parser::CondContext *ctx) {
    auto expressions = ctx->exp();
    auto result = new cond_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();

    result->lhs.reset(visit(expressions[0]).as<expr_syntax *>());
    if (ctx->Equal())
        result->op = relop::equal;
    else if (ctx->NonEqual())
        result->op = relop::non_equal;
    else if (ctx->Greater())
        result->op = relop::greater;
    else if (ctx->Less())
        result->op = relop::less;
    else if (ctx->GreaterEqual())
        result->op = relop::greater_equal;
    else if (ctx->LessEqual())
        result->op = relop::less_equal;
    result->rhs.reset(visit(expressions[1]).as<expr_syntax *>());
    return static_cast<cond_syntax *>(result);
}

// Returns antlrcpp::Any, which is constructable from any type.
// However, you should be sure you use the same type for packing and depacking
// the `Any` object. Or a std::bad_cast exception will rise. This function
// always returns an `Any` object containing a `expr_syntax *`.
antlrcpp::Any syntax_tree_builder::visitExp(C1Parser::ExpContext *ctx) {
    // Get all sub-contexts of type `exp`.
    auto expressions = ctx->exp();
    // Two sub-expressions presented: this indicates it's a expression of binary
    // operator, aka `binop`.
    if (expressions.size() == 2) {
        auto result = new binop_expr_syntax;
        // Set line and pos.
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();

        // visit(some context) is equivalent to calling corresponding visit
        // method; dispatching is done automatically by ANTLR4 runtime. For this
        // case, it's equivalent to visitExp(expressions[0]). Use reset to set a
        // new pointer to a std::shared_ptr object. DO NOT use assignment; it
        // won't work. Use
        // `.as<Type>()' to get value from antlrcpp::Any object; notice that
        // this Type must match the type used in constructing the Any object,
        // which is constructed from (usually pointer to some derived class of
        // syntax_node, in this case) returning value of the visit call.
        result->lhs.reset(visit(expressions[0]).as<expr_syntax *>());
        // Check if each token exists.
        // Returnd value of the calling will be nullptr (aka NULL in C) if it
        // isn't there; otherwise non-null pointer.
        if (ctx->Plus()) result->op = binop::plus;
        if (ctx->Minus()) result->op = binop::minus;
        if (ctx->Multiply()) result->op = binop::multiply;
        if (ctx->Divide()) result->op = binop::divide;
        if (ctx->Modulo()) result->op = binop::modulo;
        result->rhs.reset(visit(expressions[1]).as<expr_syntax *>());
        return static_cast<expr_syntax *>(result);
    }
    // Otherwise, if `+` or `-` presented, it'll be a `unaryop_expr_syntax`.
    if (ctx->Plus() || ctx->Minus()) {
        auto result = new unaryop_expr_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        if (ctx->Plus()) result->op = unaryop::plus;
        if (ctx->Minus()) result->op = unaryop::minus;
        result->rhs.reset(visit(expressions[0]).as<expr_syntax *>());
        return static_cast<expr_syntax *>(result);
    }
    // In the case that `(` exists as a child, this is an expression like `'('
    // expressions[0] ')'`.
    if (ctx->LeftParen())
        return visit(expressions[0]);  // Any already holds expr_syntax* here,
                                       // no need for
                                       // dispatch and re-patch with casting.
    // If `number` exists as a child, we can say it's a literal integer
    // expression.
    if (auto number = ctx->number()) return visit(number);

    if (ctx->lval()) {
        return static_cast<expr_syntax *>(visit(ctx->lval()).as<lval_syntax *>());
    }
}

antlrcpp::Any syntax_tree_builder::visitNumber(C1Parser::NumberContext *ctx) {
    auto result = new literal_syntax;
    if (auto intConst = ctx->IntConst()) {
        result->is_int = true;
        result->line = intConst->getSymbol()->getLine();
        result->pos = intConst->getSymbol()->getCharPositionInLine();
        auto text = intConst->getSymbol()->getText();
        if (text[0] == '0' && text[1] == 'x')                 // Hexadecimal
            result->intConst = std::stoi(text, nullptr, 16);  // std::stoi will eat '0x'
        /* you need to add other situations here */
        else if (text[0] == '0')
            result->intConst = std::stoi(text, nullptr, 8);
        else
            result->intConst = std::stoi(text, nullptr, 10);
        return static_cast<expr_syntax *>(result);
    }
    // else FloatConst
    else {
        auto FloatConst = ctx->FloatConst();
        result->is_int = false;
        result->line = FloatConst->getSymbol()->getLine();
        result->pos = FloatConst->getSymbol()->getCharPositionInLine();
        auto text = FloatConst->getSymbol()->getText();
        result->floatConst = std::stod(text, nullptr);
        return static_cast<expr_syntax *>(result);
    }
}

ptr<syntax_tree_node> syntax_tree_builder::operator()(antlr4::tree::ParseTree *ctx) {
    auto result = visit(ctx);

    if (result.is<syntax_tree_node *>())
        return ptr<syntax_tree_node>(result.as<syntax_tree_node *>());
    if (result.is<assembly *>()) return ptr<syntax_tree_node>(result.as<assembly *>());
    if (result.is<global_def_syntax *>())
        return ptr<syntax_tree_node>(result.as<global_def_syntax *>());
    if (result.is<func_def_syntax *>())
        return ptr<syntax_tree_node>(result.as<func_def_syntax *>());
    if (result.is<cond_syntax *>()) return ptr<syntax_tree_node>(result.as<cond_syntax *>());
    if (result.is<expr_syntax *>()) {
        return ptr<syntax_tree_node>(result.as<expr_syntax *>());
    }
    if (result.is<binop_expr_syntax *>())
        return ptr<syntax_tree_node>(result.as<binop_expr_syntax *>());
    if (result.is<unaryop_expr_syntax *>())
        return ptr<syntax_tree_node>(result.as<unaryop_expr_syntax *>());
    if (result.is<lval_syntax *>()) return ptr<syntax_tree_node>(result.as<lval_syntax *>());
    if (result.is<literal_syntax *>()) return ptr<syntax_tree_node>(result.as<literal_syntax *>());
    if (result.is<stmt_syntax *>()) return ptr<syntax_tree_node>(result.as<stmt_syntax *>());
    if (result.is<var_def_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<var_def_stmt_syntax *>());
    if (result.is<assign_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<assign_stmt_syntax *>());
    if (result.is<func_call_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<func_call_stmt_syntax *>());
    if (result.is<block_syntax *>()) return ptr<syntax_tree_node>(result.as<block_syntax *>());
    if (result.is<if_stmt_syntax *>()) return ptr<syntax_tree_node>(result.as<if_stmt_syntax *>());
    if (result.is<while_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<while_stmt_syntax *>());
    return nullptr;
}
