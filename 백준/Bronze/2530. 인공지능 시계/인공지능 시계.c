#include <stdio.h>
int main() {
    int a, b, c, t;
    scanf("%d %d %d\n%d", &a, &b, &c, &t);
    c += t;
    b += c / 60;
    c %= 60;
    a += b / 60;
    b %= 60;
    a %= 24;
    printf("%d %d %d", a, b, c);
    return 0;
}
