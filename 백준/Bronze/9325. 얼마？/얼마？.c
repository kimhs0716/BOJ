#include <stdio.h>
int main() {
    int n, a, b, s, o;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        s = a;
        scanf("%d", &o);
        for(int j = 0; j < o; j++){
            scanf("%d %d", &a, &b);
            s += a * b;
        }
        printf("%d\n", s);
    }
    return 0;
}
