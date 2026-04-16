#include <stdio.h>
long long int cache[30][30];
long long int c(int n, int r){
    //printf("%d %d\n", n, r);
    if(r == 0) cache[n][r] = 1;
    else if(r == 1) cache[n][r] = n;
    else if(n == 0) cache[n][r] = 0;
    else if(cache[n][r] == 0){
        if(r > n / 2) cache[n][r] = c(n, n - r);
        else cache[n][r] = c(n - 1, r - 1) + c(n - 1, r);
    }
    return cache[n][r];
}
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%lld", c(n - 1, k - 1));
    return 0;
}
