#include <stdio.h>
int main() {
    int c, k, p;
    long long int s = 0;
    scanf("%d %d %d", &c, &k, &p);
    for(int i = 1; i <= c; i++){
        s += i * (k + p * i);
    }
    printf("%lld", s);
    return 0;
}
