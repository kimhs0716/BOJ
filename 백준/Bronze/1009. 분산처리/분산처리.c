#include <stdio.h>
int main() {
    int n, a, b, res;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        a %= 10;
        b %= 4;
        res = a;
        for(int j = 0; j < b + 3; j++){
            res *= a;
            res %= 10;
        }
        printf("%d\n", res ? res : 10);
    }
    return 0;
}
