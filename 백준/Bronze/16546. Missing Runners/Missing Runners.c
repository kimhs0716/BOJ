#include <stdio.h>
int main() {
    int n, a;
    scanf("%d", &n);
    int s = n * (n + 1) / 2;
    for(int i = 0; i < n - 1; i++){
        scanf("%d", &a);
        s -= a;
    }
    printf("%d", s);
    return 0;
}
