#include <stdio.h>
int cache[9] = {1, 2, 4, };
int f(int n){
    if(cache[n] == 0) cache[n] = f(n - 3) + f(n - 2) + f(n - 1);
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
