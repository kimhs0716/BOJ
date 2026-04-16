#include <iostream>
using namespace std;
int main(){
    char *f[] = {"0", "1", "10", "11", "100", "101", "110", "111"};
    char *nf[] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    char ch[333335];
    int first = 1;
    cin >> ch;
    int i = 0;
    while(ch[i]){
        if(first){
            first = 0;
            printf(f[ch[i] - '0']);
        }
        else printf(nf[ch[i] - '0']);
        i++;
    }
    return 0;
}
