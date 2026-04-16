#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    while(1){
        string str;
        getline(cin, str);
        if(str == ".") break;
        stack<char> s;
        int len = str.length();
        int res = 1;
        for(int i = 0; i < len; i++){
            if(str[i] == '(' || str[i] == '['){
                s.push(str[i]);
                continue;
            }
            if(str[i] == ')'){
                if(s.empty() || s.top() != '('){
                    res = 0;
                    break;
                }
                s.pop();
            }
            else if(str[i] == ']'){
                if(s.empty() || s.top() != '['){
                    res = 0;
                    break;
                }
                s.pop();
            }
        }
        if(s.empty() && res == 1)
            cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
