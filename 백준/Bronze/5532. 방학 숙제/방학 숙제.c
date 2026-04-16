#include <stdio.h>
int main() {
    int l, a, b, c, d;
    scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
    int e = (a + c - 1) / c, f = (b + d - 1) / d;
    printf("%d", l - ((e > f) ? e : f));
    return 0;
}
