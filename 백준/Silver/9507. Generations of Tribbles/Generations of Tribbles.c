#include <stdio.h>
long long int cache[68] = {1, 1, 2, 4, };
long long int koong(int n){
    if(cache[n] == 0) cache[n] = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
    return cache[n];
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int k;
        scanf("%d", &k);
        printf("%lld\n", koong(k));
    }
    return 0;
}
