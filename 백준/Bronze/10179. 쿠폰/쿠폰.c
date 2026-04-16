#include <stdio.h>
int main() {
    int n;
    double a;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lf", &a);
        printf("$%.2f\n", a * 0.8);
    }
    return 0;
}
