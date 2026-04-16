#include<stdio.h>
long long int cache[100] = {0, };
long long int p(int n){
    if(cache[n] == 0){
        cache[n] = (p(n - 1) + p(n - 5));
    }
    return cache[n];
}
int main() {
    int t, n;
    cache[0] = cache[1] = cache[2] = 1;
    cache[3] = cache[4] = 2;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
        scanf("%d", &n);
        printf("%lld\n", p(n - 1));
    }
    /*p(99);
    for(int i = 1; i <= 100; i++){
        printf("%d: %lld\n", i, p(i - 1));
    }*/
    return 0;
}
