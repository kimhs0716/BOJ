#include <stdio.h>
int main() {
    int a, b, c, d, s;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    s = a + b + c + d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d", (a + b + c + d > s) ? (a + b + c + d) : s);
    return 0;
}
