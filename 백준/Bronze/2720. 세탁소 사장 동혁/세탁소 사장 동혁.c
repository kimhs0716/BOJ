#include <stdio.h>
int main() {
    int t, a, q, d, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &a);
        q = a / 25;
        a %= 25;
        d = a / 10;
        a %= 10;
        n = a / 5;
        a %= 5;
        printf("%d %d %d %d\n", q, d, n, a);
    }
    return 0;
}
