#include <iostream>
using namespace std;
int main(){
    char str[101];
    char res[51];
    cin >> str;
    int i = 0, c = 0;
    while(str[i]){
        if('A' <= str[i] && str[i] <= 'Z')
            res[c++] = str[i];
        i++;
    }
    res[c] = '\0';
    cout << res;
    return 0;
}
