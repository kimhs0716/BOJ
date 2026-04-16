#include <iostream>
using namespace std;
int main(){
    char a[1000] = {0, }, b[1000] = {0, };
    b[999] = 1;
    int n;
    cin >> n;
    while(n--){
        char t[1000] = {0, };
        for(int i = 0; i < 1000; i++){
            t[i] = a[i];
            a[i] = b[i];
        }
        for(int i = 999; i > 0; i--){
            b[i] += t[i];
            if(b[i] >= 10){
                b[i - 1]++;
                b[i] %= 10;
            }
        }
        b[0] += t[0];
    }
    bool isfirst = true;
    for(int i = 0; i < 1000; i++){
        if(a[i] == 0){
            if(!isfirst) printf("0");
        }
        else{
            printf("%d", a[i]);
            isfirst = false;
        }
    }
    return 0;
}
