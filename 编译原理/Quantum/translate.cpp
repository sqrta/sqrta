#include <string.h>
#include <iostream>
#include <set>
#include "choose.cpp"
#define N 300
#define Visited 1
using namespace std;

bool overlap(Instruction a, Instruction b) {  //两条指令有重叠返回true，否则false
    if (!a.is_operation || !b.is_operation) return true;
    for (int i = 0; i < a.qubitsnum; i++) {
        for (int j = 0; j < b.qubitsnum; j++)
            if (a.qubits[i] == b.qubits[j]) return true;
    }
    return false;
}

void insert_codes_qubit(Instruction a, set<Qubit> Q) {}

bool check_code_overlap_set(Instruction a, set<Qubit> Q) {
    for (int i = 0; i < a.qubitsnum; i++) {
        auto q = a.get_qubit(i);
        if (Q.find(q) != Q.end()) return true;
    }
    return false;
}

main() {
    Instruction codes[N];
    Qubit qubits[50];
    Lexer(codes, qubits);

    int i;
    for (i = 0; qubits[i].sign; i++) {
        cout << qubits[i].getname() << ": ";
        qubits[i].printque();
        cout << endl;
        qubits[i].mark = 0;
    }
    int undeal_qubits_num = i;

    // for (i = 1; codes[i].line; i++) codes[i].print();

    for (i = 1; codes[i].line; i++) {
        if (codes[i].is_operation == false) continue;
        if (codes[i].mark == Visited) continue;
        
        codes[i].mark = Visited;
        set<Qubit> qubits_set;
        int j;
        for (j = 0; j < codes[i].qubitsnum; j++) {
            Qubit q = codes[i].get_qubit(j);
            qubits_set.insert(q);
        }
        int cur = i;
        int tail = cur;
        while (1) {
            printf("cur: %d,tail: %d\n",cur,tail);
            j = tail + 1;
            while (codes[j].line) {
                if (check_code_overlap_set(codes[j], qubits_set)) break;
                j++;
            }
            printf("j: %d\n",j);
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
        break;
        if (cur == i) {
            codes[i].mark = Visited;
            continue;
        } else {
            i--;
            
            continue;
        }
        
    }
    cout << "translate done!" << endl;
    for (i = 1; codes[i].line; i++) codes[i].print();
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