#include <iostream>
#include <string>

using namespace std;

main() {
    char tmp[50];
    int state[4] = {};
    cin >> tmp;
    while (cin >> tmp) {
        if (tmp[4] == '0') {
            if (tmp[5] == '0')
                state[0]+= std::stoi(tmp+8);
            else
                state[1]+=std::stoi(tmp+8);
        }
        else{
            if (tmp[5]=='0') state[2]+=std::stoi(tmp+8);
            else state[3]+=std::stoi(tmp+8);
        }
    }
    cout<<"00: "<<state[0]<<endl;
    cout<<"01: "<<state[1]<<endl;
    cout<<"10: "<<state[2]<<endl;
    cout<<"11: "<<state[3]<<endl;
}