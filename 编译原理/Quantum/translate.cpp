#include <string.h>
#include <iostream>
#include <set>
//#include "choose.cpp"
#include "levelize.cpp"
#define N 300
#define IFINITY 9999
#define Visited 1
using namespace std;

void print_qubit(Qubit a) {
    cout << a.name << ": ";
    for (int i = 0; i < a.tail; i++) {
        printf("%d ", a.queue[i]->line);
    }
    cout << endl;
}

void insert_codes_qubit(Instruction a, set<Qubit*>& Q) {
    for (int i = 0; i < a.qubitsnum; i++) {
        Q.insert(a.qubits[i]);
    }
}

bool check_code_overlap_set(Instruction a, set<Qubit*> Q) {
    for (int i = 0; i < a.qubitsnum; i++) {
        auto q = a.get_qubit(i);
        if (Q.find(q) != Q.end()) return true;
    }
    return false;
}
/**/
bool judge_ins_optimization(Instruction codes[], int i) {
    set<Qubit*> judge_set;
    insert_codes_qubit(codes[i], judge_set);
    int j = i + 1;
    while (overlap(codes[i], codes[j]) == false) {
        if (check_code_overlap_set(codes[j], judge_set) == true) return true;
        j++;
    }
    return false;
}

int find_next_level(set<Qubit*> qubits_set,
                    int l) {  //找到level l之后和集合qubits_set重合的最近的level
    auto start = qubits_set.begin();
    int min = IFINITY;
    for (; start != qubits_set.end(); start++) {
        auto p = *start;
        int i;
        for (i = 0; i < p->tail; i++) {
            if (p->queue[i]->line > l) break;
        }
        if (i < p->tail && p->queue[i]->line < min) min = p->queue[i]->line;
    }
    return min;
}

main() {
    Instruction codes[N];
    Qubit qubits[50];
    Lexer(codes, qubits);
    Level tower[N];

    int total_level = levelize(tower, codes, qubits);
    int i;
    for (i = 0; qubits[i].sign; i++)
        ;
    int total_qubits = i;
    for (i = 0; qubits[i].sign; i++) {
        print_qubit(qubits[i]);
        cout << endl;
        qubits[i].mark = 0;
    }
    /**/
    for (i = 1; i <= total_level; i++) {
        //tower[i].print();
        if (tower[i].is_operation == false) continue;
        auto p = tower[i].head->next;
        while (p != NULL) {  //一次while处理一条指令的合并

            if (p->mark == Visited) {
                p = p->next;
                continue;
            }
            Instruction* ins_unit[10] = {p};  // ins_unit装着所有可以并到一起的ins的指针
            int unit_begin = 1;               // ins_unit数组下一个加入的ins存放的下标
            p->mark = Visited;
            set<Qubit*> qubits_set;
            insert_codes_qubit(*p, qubits_set);
            int cur_level = i;
            /*
            if (tower[i].line==30){
                cout<<"***************"<<endl;
                p->printcode();
                printf("\n##########\n");
                for (int u=0;u<9;u++){
                    tower[i+u].print();
                }
                cout<<"***************"<<endl;
            }*/
            while (qubits_set.size() < total_qubits) {
                //if (tower[i].line==30)
                //printf("cur: %d, begin: %d, size: %d\n",cur_level,unit_begin,qubits_set.size());
                auto tmp_level =
                    find_next_level(qubits_set, cur_level);  //找到和当前set重合的下一个level
                if (tmp_level == IFINITY) break;
                cur_level = tmp_level;

                auto next_instruction = tower[cur_level].find_overlap_instruction(qubits_set);
                next_instruction->mark = Visited;
                ins_unit[unit_begin] = next_instruction;
                unit_begin++;
                insert_codes_qubit(*next_instruction, qubits_set);
            }
            cur_level = ins_unit[unit_begin - 1]->line;
            unit_begin--;
            //printf("begin: %d, cur\n",unit_begin);
            for (int u = unit_begin - 1; u >= 0; u--) {
                auto ins = ins_unit[u];
                int l = ins->line;
                if (l==cur_level - unit_begin + u) continue;
                tower[l].del(ins);
                /*
            if (tower[i].line==30){
                printf("break\n");
            }                */
                tower[cur_level - unit_begin + u].insert(ins);
            }

            //return 0;
        }
    }
    for (i = 1; i <= total_level; i++) {
        tower[i].print();
    }
    /*
        int i;

        int undeal_qubits_num = i;

        // for (i = 1; codes[i].line; i++) codes[i].print();

        for (i = 1; codes[i].line; i++) {
            if (codes[i].is_operation == false) continue;
            if (codes[i].mark == Visited) continue;

            codes[i].mark = Visited;
            set<Qubit> qubits_set;

            int j;
            insert_codes_qubit(codes[i],qubits_set);
            //if (judge_ins_optimization(codes,i)==false) continue;
            int cur = i;
            int tail = cur;
            while (1) {
                //printf("cur: %d,tail: %d\n",cur,tail);
                j = tail + 1;
                while (codes[j].line) {
                    if (check_code_overlap_set(codes[j], qubits_set)) break;
                    j++;
                }
                //printf("j: %d\n",j);
                if (codes[j].line==0) break;
                codes[j].mark = Visited;
                if (j == tail + 1) break;
                Instruction tmp[20]={};
                for (int u = 0; cur + u <= tail; u++) {
                    tmp[u]=codes[cur+u];
                }
                int size=tail-cur+1;
                for (int u=tail+1;u<j;u++){
                    codes[u-size]=codes[u];
                }
                for (int u=0;u<size;u++){
                    codes[j-size+u]=tmp[u];
                }
                cur = j - (tail - cur + 1);
                tail = j;
                for (int u = 0; u < codes[j].qubitsnum; u++) {
                    qubits_set.insert(codes[j].qubits[u]);
                }
            }
            if (cur == i) {
                codes[i].mark = Visited;
                continue;
            } else {
                i--;

                continue;
            }

        }
        cout << "translate done!" << endl;
        for (i = 1; codes[i].line; i++){
            printf("%d:\t%s\n",i,codes[i].code);
            //codes[i].print();
        }
        /*
        int lastline;
        int newline=1;
        for (i=2,lastline=1;codes[i].line;i++){
            int j;
            for (j=lastline;j<i;j++){
                if (overlap(codes[i],codes[j])) break;
            }
            if (j<i){
                cout<<newline<<": ";
                for (j=lastline;j<i;j++)
                cout<<codes[j].code<<" ";
                cout<<endl;
                lastline=i;
                newline++;
            }
        }*/
}