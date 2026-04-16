#include <stdio.h>
int main() {
    int n, t, a, s;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        s = 0;
        scanf("%d", &t);
        for(int j = 0; j < t; j++){
            scanf("%d", &a);
            s += a;
        }
        printf("%d\n", s);
    }
    return 0;
}
