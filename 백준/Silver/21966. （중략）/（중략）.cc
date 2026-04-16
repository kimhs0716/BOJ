#include <iostream>
#include <string>
using namespace std;
int main(){
    int n; cin >> n;
    string str; cin >> str;
    if(n <= 25){
        cout << str << endl;
        return 0;
    }
    int idx = 11, dot_cnt = 0;
    for(; idx < n - 12; idx++){
        if(str[idx] == '.') goto LAST;
    }
    for(int i = 0; i < 11; i++){
        cout << str[i];
    }
    cout << "...";
    for(int i = n - 11; i < n; i++){
        cout << str[i];
    }
    cout << endl;
    return 0;
LAST:
    for(int i = 0; i < 9; i++){
        cout << str[i];
    }
    cout << "......";
    for(int i = n - 10; i < n; i++){
        cout << str[i];
    }
    cout << endl;
    return 0;
}
