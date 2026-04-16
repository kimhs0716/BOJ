#include <stdio.h>
int main() {
    long long int n;
    scanf("%lld", &n);
    n %= 45678;
    printf("%d", (n * (n + 1) / 2 * 5 - (n * (n - 1) + n) + 1) % 45678);
    return 0;
}
