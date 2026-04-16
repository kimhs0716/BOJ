#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    int n = 0;
    while(getline(cin, str)){
        if(str == "고무오리 디버깅 끝") break;
        if(str == "문제") n++;
        if(str == "고무오리") n += (n ? -1 : 2);
    }
    if(n) cout << "힝구";
    else cout << "고무오리야 사랑해";
    return 0;
}
