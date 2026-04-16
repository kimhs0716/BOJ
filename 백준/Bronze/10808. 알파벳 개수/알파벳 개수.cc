#include <iostream>
using namespace std;
int main(){
    int alpha[26] = {0, };
    char str[101];
    cin >> str;
    int i = 0;
    while(str[i]){
        alpha[str[i++] - 'a']++;
    }
    for(i = 0; i < 26; i++)
        cout << alpha[i] << " ";
    return 0;
}
