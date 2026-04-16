#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    int t;
    int c = 0;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int len = str.length();
        stack<char> s;
        s.push(str[0]);
        for(int i = 1; i < len; i++){
            if(!s.empty() && s.top() == str[i]) s.pop();
            else s.push(str[i]);
        }
        if(s.empty()) c++;
    }
    cout << c << endl;
    return 0;
}
