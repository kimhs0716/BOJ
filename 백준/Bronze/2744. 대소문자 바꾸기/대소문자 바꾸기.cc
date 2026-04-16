#include <iostream>
#include <string>
using namespace std;
int main(){
    string s; cin >> s;
    for(int i = 0; i < s.length(); i++){
        if('a' <= s[i] && s[i] <= 'z') cout << char(s[i] - 'a' + 'A');
        else cout << char(s[i] - 'A' + 'a');
    }
    cout << endl;
    return 0;
}