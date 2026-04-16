#include <iostream>
#include <string>
#include <stack>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;
int main(){
    string s;
    getline(cin, s);
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '<') {
            while(!st.empty()){
                cout << st.top();
                st.pop();
            }
            cout << '<';
            while(s[++i] != '>') cout << s[i];
            cout << s[i];
        }
        else if(s[i] == ' '){
            while(!st.empty()){
                cout << st.top();
                st.pop();
            }
            cout << ' ';
        }
        else{
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    return 0;
}
