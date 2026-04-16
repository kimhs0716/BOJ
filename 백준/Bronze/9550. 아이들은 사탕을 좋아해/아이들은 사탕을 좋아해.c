#include <stdio.h>
int main() {
    int t, n, k, a;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d", &n, &k);
        int s = 0;
        for(int j = 0; j < n; j++){
            scanf("%d", &a);
            s += a / k;
        }
        printf("%d\n", s);
    }
    return 0;
}
