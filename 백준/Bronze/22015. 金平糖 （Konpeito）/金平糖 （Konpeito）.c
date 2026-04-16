#include <stdio.h>
int main() {
    int a, b, c, max = 0;
    scanf("%d %d %d", &a, &b, &c);
    max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    printf("%d", 3 * max - a - b - c);
    return 0;
}
