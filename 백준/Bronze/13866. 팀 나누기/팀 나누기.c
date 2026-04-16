#include <stdio.h>
#include <stdlib.h>
int main() {
    int a, b, c, d, e, f, g;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    e = abs(a + b - c - d);
    f = abs(a + c - b - d);
    g = abs(a + d - b - c);
    if(e < f && e < g) printf("%d", e);
    else if(f < e && f < g) printf("%d", f);
    else printf("%d", g);
    return 0;
}
