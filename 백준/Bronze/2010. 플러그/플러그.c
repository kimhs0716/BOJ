#include <stdio.h>
int main() {
    int a, n, s = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        s += a;
    }
    printf("%d", s - n);
    return 0;
}
