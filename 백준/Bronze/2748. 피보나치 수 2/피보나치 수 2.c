#include <stdio.h>
long long int cache[91] = {0, };
long long int fib(int);
int main(){
    cache[1] = cache[2] = 1;
    int n;
    scanf("%d", &n);
    printf("%lld\n", fib(n));
    return 0;
}
long long int fib(int n){
    if(cache[n] == 0)
        cache[n] = fib(n - 1) + fib(n - 2);
    return cache[n];
}
