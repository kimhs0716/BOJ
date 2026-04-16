#include <stdio.h>
#include <math.h>
int isprime(int n){
    if(n < 2) return 0;
    double loop = pow((double) n, 0.5);
    for(int i = 2; i <= loop; i++)
        if(n % i == 0) return 0;
    return 1;
}
int main(){
    int n, sum = 0, min = 0, m;
    scanf("%d %d", &m, &n);
    for(int i = n; i >= m; i--){
        if(isprime(i)){
            min = i;
            sum += i;
        }
    }
    if(sum){
        printf("%d\n%d", sum, min);
    }
    else printf("-1");
    return 0;
}
