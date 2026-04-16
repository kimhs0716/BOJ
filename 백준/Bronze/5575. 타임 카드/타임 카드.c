#include <stdio.h>
int main() {
    int a, b, c, d, e, f;
    for(int i = 0; i < 3; i++){
        scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
        d -= a;
        e -= b;
        f -= c;
        (f < 0) && (f += 60, e -= 1);
        (e < 0) && (e += 60, d -= 1);
        printf("%d %d %d\n", d, e, f);
    }
    return 0;
}
