#include <stdio.h>
int main() {
    int n, a, b, c, d, e, f, g, h;
    scanf("%d", &n);
    for(int k = 0; k < n; k++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        scanf("%d %d %d %d", &e, &f, &g, &h);
        a += e;
        b += f;
        c += g;
        d += h;
        (a < 1) && (a = 1);
        (b < 1) && (b = 1);
        (c < 0) && (c = 0);
        printf("%d\n", a + 5 * b + 2 * (c + d));
    }
    return 0;
}
