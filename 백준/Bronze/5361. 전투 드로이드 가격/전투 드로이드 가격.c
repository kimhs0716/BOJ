#include <stdio.h>
int main() {
    double arr[5] = {350.34, 230.90, 190.55, 125.30, 180.90};
    int n, a;
    double s;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        s = 0;
        for(int j = 0; j < 5; j++){
            scanf("%d", &a);
            s += a * arr[j];
        }
        printf("$%.2lf\n", s);
    }
    return 0;
}
