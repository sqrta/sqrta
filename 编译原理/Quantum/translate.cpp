#include <iostream>
#include <string.h>
#include "choose.cpp"
#define N 300

bool overlap(Instruction a,Instruction b){  //两条指令有重叠返回true，否则false
    if (!a.is_operation || !b.is_operation) return true;
    for (int i=0;i<a.qubitsnum;i++){
        for (int j=0;j<b.qubitsnum;j++)
            if (a.qubits[i]==b.qubits[j]) return true;
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
    }
    for (i = 1; codes[i].line; i++) codes[i].print();
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
    }
}