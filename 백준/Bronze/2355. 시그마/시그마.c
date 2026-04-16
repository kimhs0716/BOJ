#include <stdio.h>
int main() {
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    if(a > b){
        long long int t = a;
        a = b;
        b = t;
    }
    printf("%lld", (a + b) * (b - a + 1) / 2);
    return 0;
}
