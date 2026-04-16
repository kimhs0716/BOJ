#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    int n, k;
    cin >> n >> k >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'R') k--;
    }
    if(k > 0) cout << 'R' << endl;
    else cout << 'W' << endl;
    return 0;
}