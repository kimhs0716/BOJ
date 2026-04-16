#include <stdio.h>
int main() {
    int a, b, c, n, m = 0, t;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(a == b && b == c)
            t = 10000 + a * 1000;
        else if(a == b)
            t = 1000 + a * 100;
        else if(c == b)
            t = 1000 + c * 100;
        else if(a == c)
            t = 1000 + c * 100;
        else
            t = 100 * ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c));
        m = (m > t) ? m : t;
    }
    printf("%d", m);
    return 0;
}
