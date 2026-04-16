#include <stdio.h>
int main() {
    int x, y, n, a, b;
    scanf("%d %d %d", &x, &y, &n);
    double min = (double)x / y;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        min = (min > (double)a / b) ? ((double)a / b) : min;
    }
    printf("%.2lf", min * 1000);
    return 0;
}
