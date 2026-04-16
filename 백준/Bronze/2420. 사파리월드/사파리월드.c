#include <stdio.h>
int main() {
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", (a - b) * ((a - b > 0) ? 1 : -1));
    return 0;
}
