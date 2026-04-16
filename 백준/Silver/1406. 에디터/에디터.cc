#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    stack<char> s1, s2;
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        s1.push(str[i]);
    }
    int n;
    cin >> n;
    while(n--){
        char cmd;
        scanf(" %c", &cmd);
        if(cmd == 'L'){
            if(s1.empty()) continue;
            s2.push(s1.top());
            s1.pop();
        }
        else if(cmd == 'D'){
            if(s2.empty()) continue;
            s1.push(s2.top());
            s2.pop();
        }
        else if(cmd == 'B'){
            if(s1.empty()) continue;
            s1.pop();
        }
        else{
            scanf(" %c", &cmd);
            s1.push(cmd);
        }
    }
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    while(!s2.empty()){
        printf("%c", s2.top());
        s2.pop();
    }
    return 0;
}
