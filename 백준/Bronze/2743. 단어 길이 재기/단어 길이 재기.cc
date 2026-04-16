#include <iostream>
using namespace std;
int main(){
    char str[101];
    cin >> str;
    int i = 0;
    while(str[i]){
        i++;
    }
    cout << i;
    return 0;
}
