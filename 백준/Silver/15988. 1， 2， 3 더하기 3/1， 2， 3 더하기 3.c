#include <stdio.h>
#define mod 1000000009
int cache[1000001] = {1, 2, 4, };
int f(int n){
    if(cache[n] == 0) cache[n] = ((f(n - 3) + f(n - 2)) % mod + f(n - 1)) % mod;
    return cache[n];
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int k;
        scanf("%d", &k);
        printf("%d\n", f(k - 1));
    }
    return 0;
}
