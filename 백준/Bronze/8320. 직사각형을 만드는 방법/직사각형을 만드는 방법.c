#include <stdio.h>
#include <math.h>
int d(int n){
    int res = 0;
    double loop = pow((double)n, 0.5);
    for(int i = 1; i <= loop; i++){
        if(n % i == 0) res += 2;
    }
    return res;
}
int main(){
    int n, a, b, s = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        s += (d(i) + 1) / 2;
        //printf("%d %d\n", d(i), (d(i) + 1) / 2);
    }
    printf("%d", s);
    return 0;
}
