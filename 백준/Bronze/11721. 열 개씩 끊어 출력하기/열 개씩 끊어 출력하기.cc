#include <iostream>
using namespace std;
int main(){
    char str[101] = {0, };
    cin >> str;
    for(int i = 0; i < 100;){
        cout << str[i++];
        if(i % 10 == 0) cout << endl;
        if(str[i] == '\0') break;
    }
    return 0;
}
