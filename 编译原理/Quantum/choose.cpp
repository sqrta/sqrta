#include <stdio.h>
#include <string.h>
#include <iostream>
#define N 300
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
        for (int i = 0; i < tail; i++) cout << queue[i]<<",";
        cout << endl;
    }
    int sign = 0;

   private:
    char name[10] = {};
    int queue[100] = {};
    int tail = 0;
};

Qubit qubits[N];

int hashi(char* name) {
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

char* cutoperation(char* instruction) {
    int i, j;
    for (i = 0; instruction[i]; i++) {
        if (instruction[i] == ' ') {
            return instruction + i + 1;
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

main() {
    char codes[200][20];
    int i = 1;
    int findqubit[100] = {}, u = 0;
    while (fgets(codes[i], 100, stdin) != NULL) {
        cout << codes[i];
        char* code = cutoperation(codes[i]);
        while (1) {
            auto qub = getqubit(code);
            if (qub == NULL) break;
            int tmp = hashi(qub);
            //cout << qub << ": " << tmp << endl;
            if (qubits[tmp].sign == 0) {
                qubits[tmp].setname(qub);
                qubits[tmp].sign = 1;
                findqubit[u] = tmp;
                u++;
            }

            qubits[tmp].insert(i);
        }
        i++;
    }
    cout << endl;
    for (i = 0; i < u; i++) {
        int tmp = findqubit[i];
        cout << qubits[tmp].getname() << ": ";
        qubits[tmp].printque();
        cout << endl;
    }
}