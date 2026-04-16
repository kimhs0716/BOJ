#include <stdio.h>
#include <stdlib.h>
int main() {
    char a[15], b[8], c[15], d[8];
    long long int l1, l2;
    scanf("%s %s %s %s", a, b, c, d);
    sprintf(a, "%s%s", a, b);
    sprintf(c, "%s%s", c, d);
    l1 = atoll(a);
    l2 = atoll(c);
    printf("%lld", l1 + l2);
    return 0;
}
