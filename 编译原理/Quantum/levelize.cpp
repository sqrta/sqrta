#include <string.h>
#include <iostream>
#include <set>
#include "choose.cpp"
#define N 300
using namespace std;

bool overlap(Instruction a, Instruction b) {  //两条指令有重叠返回true，否则false
    if (!a.is_operation || !b.is_operation) return true;
    for (int i = 0; i < a.qubitsnum; i++) {
        for (int j = 0; j < b.qubitsnum; j++)
            if (a.qubits[i] == b.qubits[j]) return true;
    }
    return false;
}

class Level {
   public:
    Instruction level_head;
    Instruction* head = &level_head;
    int line = 0;
    int length;
    bool is_operation = true;
    Instruction* tail = head;
    void insert(Instruction* a) {
        tail->next = a;
        a->next = NULL;
        tail = a;
    }
    void print() {
        Instruction* p = head->next;
        cout << line << ": ";
        while (p != NULL) {
            p->printcode();
            cout << ' ';
            p = p->next;
        }
        cout << endl;
    }
    void del(Instruction* a) {
        Instruction* p = head;
        while (p->next != NULL) {
            if (p->next == a) break;
            p=p->next;
        }
        if (p->next == NULL){
            return;
        } 
        if (p->next == tail) tail = p;
        p->next = p->next->next;
        
    }
    Instruction* find_overlap_instruction(set<Qubit*> Q) {  //找到level l中和Q重合的指令
        auto p = head->next;
        while (p) {
            for (int i = 0; i < p->qubitsnum; i++) {
                if (Q.find(p->qubits[i]) != Q.end()) return p;
            }
            p = p->next;
        }
        return NULL;
    }
};

int levelize(Level tower[], Instruction codes[], Qubit qubits[]) {
    int lastline, i;
    int newline = 1;
    for (i = 2, lastline = 1; codes[lastline].line; i++) {
        int j;
        tower[newline].is_operation = codes[lastline].is_operation;
        for (j = lastline; j < i; j++) {
            if (overlap(codes[i], codes[j])) break;
        }
        if (j < i || codes[i].line == 0) {
            for (j = lastline; j < i; j++) {
                tower[newline].insert(&(codes[j]));
                codes[j].line = newline;
            }
            lastline = i;
            tower[newline].line = newline;
            newline++;
        }
    }
    for (i=1;i<newline;i++) tower[i].print();
    return newline - 1;
}