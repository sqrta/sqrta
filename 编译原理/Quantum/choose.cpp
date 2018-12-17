#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#define N 300
#define Measure 1
#define Operation 0
#define Decline 2
using namespace std;
class Qubit;
class Instruction;

class Qubit {
   public:
    char* getname() { return name; }
    void insert(Instruction* n) {
        queue[tail] = n;
        tail++;
    }
    int tail = 0;
    void setname(char* newname) { strcpy(name, newname); }
    /*void printque() {
        for (int i = 0; i < tail; i++) cout << queue[i]->line << ",";
        cout << endl;
    }*/
    int sign = 0;
    int mark = 0;  // can do every thing you want, is not used in class
    bool operator==(const Qubit& a) const {
        if (strcmp(a.name, name) == 0)
            return true;
        else
            return false;
    }
    bool operator<(const Qubit& a) const { return strcmp(name, a.name) < 0; }

    char name[10] = {};
    Instruction* queue[100] = {};
    
};

class Instruction {
   public:
    int line = 0;
    char prefix[20];
    char code[100];
    bool is_operation = false;
    bool is_void = false;
    int mark = 0;  // can do every thing you want, is not used in class
    void setprefix(char* operation) { strcpy(prefix, operation); }
    Qubit *qubits[10];
    int qubitsnum = 0;  //比特数量
    Qubit* get_qubit(int i) { return qubits[i]; }
    void insertQubit(Qubit* q) {
        qubits[qubitsnum] = q;
        qubitsnum++;
    }
    void print() {
        cout <<  code << endl << "qubits: ";
        for (int i = 0; i < qubitsnum; i++) {
            cout << qubits[i]->getname() << " ";
        }
        cout << endl << endl;
    }
    void printcode() {
        if (is_void) return;
        cout << code;
    }
    Instruction* next=NULL;
};

int hashi(Qubit* qubits, char* name) {
    int i, sum;
    for (i=0;qubits[i].sign;i++){
        if (strcmp(name,qubits[i].name)==0)
            return i;
    }
    return i;
    /*
    for (i = 0, sum = 0; name[i]; i++) {
        if (name[i] == ' ') continue;
        sum += name[i] - 'A';
    }
    while (qubits[sum].sign) {
        /*cout << "new:" << name << "\norigin:" << qubits[sum].getname()
             << "compare:" << strcpy(qubits[sum].getname(), name) << endl;
        if (strcmp(qubits[sum].getname(), name) == 0) break;
        sum++;
    }
    return sum;*/
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

void Lexer(Instruction codes[], Qubit qubits[]) {
    // char codes[200][20];
    int j = 1, i;
    //Qubit qubits[N];
    int findqubit[100] = {}, u = 0;
    while (fgets(codes[j].code, 100, stdin) != NULL) {
        char instruction[100] = {};
        strcpy(instruction, codes[j].code);
        if (instruction[0] == '\n' || instruction[0] == '\0') continue;
        codes[j].code[strlen(codes[j].code) - 1] = 0;
        // cout << codes[j].code;
        codes[j].line = j;
        i = j;
        j++;
        

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
                //findqubit[u] = tmp;  // findqubit数组记录了所有qubit的哈希值，可以找到qubit；
                u++;
            }
            qubits[tmp].insert(&codes[i]);
            codes[i].insertQubit(&qubits[tmp]);
        }
    }
    /*
    for (i = 0; i < u; i++) {
        qubitqueue[i] = qubits[findqubit[i]];
    }
    cout << endl;*/
}