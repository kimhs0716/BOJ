#include <stdio.h>
int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n, d;
        scanf("%d %d", &n, &d);
        int count = 0;
        for(int j = 0; j < n; j++){
            double v, f, c;
            scanf("%lf %lf %lf", &v, &f, &c);
            if(c * d / v <= f) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
