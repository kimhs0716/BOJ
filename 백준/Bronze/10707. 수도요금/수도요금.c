#include <stdio.h>
int main() {
    int a, b, c, d, p;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);
    a *= p;
    b += (p > c) * ((p - c) * d);
    printf("%d", (a > b) ? b : a);
    return 0;
}
