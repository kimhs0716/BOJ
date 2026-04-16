#include <stdio.h>
int clop(int n){
    int res = 0;
    while(n){
        res += ((n % 10) % 3 == 0 && n % 10 != 0);
        n /= 10;
    }
    return res;
}
int main(){
    int n, c = 0;
    scanf("%d", &n);
    for(int i = 3; i <= n; i++)
        c += clop(i);
    printf("%d", c);
    return 0;
}
