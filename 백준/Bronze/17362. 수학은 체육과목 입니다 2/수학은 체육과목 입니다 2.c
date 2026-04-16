#include <stdio.h>
int main() {
    int a[] = {2, 1, 2, 3, 4, 5, 4, 3, 2, 1, 2, 3, 4, 5, 4, 3};
    int n;
    scanf("%d", &n);
    printf("%d", a[n % 16]);
    return 0;
}
