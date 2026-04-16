#include <stdio.h>
int main() {
    int n, s1, a, c;
    double s2, b;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        s1 = 0;
        s2 = 0;
        scanf("%d", &c);
        for(int j = 0; j < c; j++){
            scanf("%d %lf", &a, &b);
            s1 += a;
            s2 += a * b;
        }
        printf("%d %.1lf\n", s1, s2 / s1);
    }
    return 0;
}
