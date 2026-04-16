#include <stdio.h>
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a == b && b == c)
        printf("%d\n", 10000 + a * 1000);
    else if(a == b)
        printf("%d\n", 1000 + a * 100);
    else if(c == b)
        printf("%d\n", 1000 + c * 100);
    else if(a == c)
        printf("%d\n", 1000 + c * 100);
    else
        printf("%d\n", 100 * ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c)));
    return 0;
}
