#include <iostream>
using namespace std;
int fac2dec(int n);
int fac[6] = {1, 1, 2, 6, 24, 120};
int main(){
    int n;
    while(scanf("%d", &n)){
        if(n == 0) break;
        printf("%d\n", fac2dec(n));
    }
    return 0;
}
int fac2dec(int n){
    int res = 0, i = 1;
    while(n){
        res += (n % 10) * fac[i];
        n /= 10;
        i++;
    }
    return res;
}
