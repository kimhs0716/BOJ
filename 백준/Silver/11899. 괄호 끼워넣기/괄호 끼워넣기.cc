#include <iostream>
#include <stack>
using namespace std;
int main(){
    int c = 0;
    string str;
    cin >> str;
    stack<int> s;
    s.push(str[0]);
    for(int i = 1; i < str.length(); i++){
        if(str[i] == '('){
            s.push('(');
            continue;
        }
        if(s.empty() || str[i] == s.top())
            s.push(str[i]);
        else s.pop();
    }
    cout << s.size() << endl;
    return 0;
}
