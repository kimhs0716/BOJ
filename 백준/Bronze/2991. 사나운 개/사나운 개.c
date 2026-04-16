#include <stdio.h>
int main(){
    int a, b, c, d, p, m, n;
    scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &p, &m, &n);
    p -= 1;
    m -= 1;
    n -= 1;
    printf("%d\n", (p % (a + b) < a) + (p % (c + d) < c));
    printf("%d\n", (m % (a + b) < a) + (m % (c + d) < c));
    printf("%d\n", (n % (a + b) < a) + (n % (c + d) < c));
    return 0;
}
