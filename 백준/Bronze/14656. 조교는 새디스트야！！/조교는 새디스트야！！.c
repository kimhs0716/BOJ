#include <stdio.h>
int main() {
    int a, n, count = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a);
        count += (a != i);
    }
    printf("%d", count);
    return 0;
}
