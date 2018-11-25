#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#define N 300
#define Measure 1
#define Operation 0
#define Decline 2
using namespace std;

class Qubit {
   public:
    char* getname() { return name; }
    void insert(int n) {
        queue[tail] = n;
        tail++;
    }
    void setname(char* newname) { strcpy(name, newname); }
    void printque() {
        for (int i = 0; i < tail; i++) cout << queue[i] << ",";
        cout << endl;
    }
    int sign = 0;
    bool operator== (const Qubit &a) const{
        if (strcmp(a.name,name)==0) return true;
        else return false;
    }
   private:

     char name[10] = {};
    int queue[100] = {};
    int tail = 0;
};

class Instruction {
   public:
    int line = 0;
    char prefix[20];
    char code[100];
    bool is_operation = false;
    bool is_void=false;
    void setprefix(char* operation) { strcpy(prefix, operation); }
    Qubit qubits[10];
    int qubitsnum = 0;  //比特数量
    void insertQubit(Qubit q) {
        qubits[qubitsnum] = q;
        qubitsnum++;
    }
    void print() {
        cout << line << ": " << code << endl<<"qubits: ";
        for (int i = 0; i < qubitsnum; i++) {
            cout << qubits[i].getname() << " ";
        }
        cout << endl << endl;
    }
    void printcode(){
        if (is_void) return;
        cout<<code;
    }
};

int hashi(Qubit* qubits, char* name) {
    int i, sum;
    for (i = 0, sum = 0; name[i]; i++) {
        if (name[i] == ' ') continue;
        sum += name[i] - 'A';
    }
    while (qubits[sum].sign) {
        /*cout << "new:" << name << "\norigin:" << qubits[sum].getname()
             << "compare:" << strcpy(qubits[sum].getname(), name) << endl;*/
        if (strcmp(qubits[sum].getname(), name) == 0) break;
        sum++;
    }
    return sum;
}

char* cutoperation(char* instruction, char*& code) {
    int i, j;
    for (i = 0; instruction[i]; i++) {
        if (instruction[i] == ' ') {
            code = instruction + i + 1;
            instruction[i] = 0;
            return instruction;
        }
    }
    return NULL;
}

char* getqubit(char*& code) {
    int i;
    // printf("code[0]: %d\n",code[0]);
    if (code[0] == 0 || code[0] == '\n') return NULL;
    for (i = 0;; i++) {
        if (code[i] == ',' || code[i] == 0 || code[i] == ';') {
            code[i] = 0;
            auto tmp = code;
            code = code + i + 1;

            return tmp;
        }
    }
}

int judge(char* instruction) {
    if (strcmp(instruction, "qreg") == 0 || strcmp(instruction, "creg") == 0)
        return Decline;
    else if (strcmp(instruction, "measure") == 0)
        return Measure;
    else
        return Operation;
}

void Lexer(Instruction codes[], Qubit qubitqueue[]) {
    // char codes[200][20];
    int j = 1, i;
    Qubit qubits[N];
    int findqubit[100] = {}, u = 0;
    while (fgets(codes[j].code, 100, stdin) != NULL) {
        char instruction[100] = {};
        strcpy(instruction, codes[j].code);
        codes[j].code[strlen(codes[j].code)-1]=0;
        // cout << codes[j].code;
        codes[j].line = j;
        i = j;
        j++;
        if (instruction[0] == '\n' || instruction[0] == '\0') continue;
        char* code;
        char* prefix = cutoperation(instruction, code);
        if (judge(prefix) != Operation) {  //判断是否为门操作
            codes[i].is_operation = false;
            continue;
        }
        codes[i].is_operation = true;
        while (1) {
            auto qub = getqubit(code);
            if (qub == NULL) break;
            int tmp = hashi(qubits, qub);
            // cout << qub << ": " << tmp << endl;
            if (qubits[tmp].sign == 0) {
                qubits[tmp].setname(qub);
                qubits[tmp].sign = 1;
                findqubit[u] = tmp;  // findqubit数组记录了所有qubit的哈希值，可以找到qubit；
                u++;
            }
            qubits[tmp].insert(i);
            codes[i].insertQubit(qubits[tmp]);
        }
    }
    for (i = 0; i < u; i++) {
        qubitqueue[i] = qubits[findqubit[i]];
    }
    cout << endl;
}