#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, res = 0;
    scanf("%d", &n);
    int a, b, x, y, x0, y0;
    scanf("%d %d", &a, &b);
    x0 = a, y0 = b;
    for(int i = 0; i < n - 1; i++){
        scanf("%d %d", &x, &y);
        if(a == x)
            res += abs(y - b);
        else res += abs(a - x);
        a = x, b = y;
    }
    if(a == x0) res += abs(y0 - b);
    else res += abs(x0 - a);
    printf("%d", res);
    return 0;
}
