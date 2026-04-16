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
    int t, n, count = 0;
    scanf("%d", &t);
    for(int asdf = 0; asdf < t; asdf++){
        scanf("%d", &n);
        if(isprime(n)) count++;
    }
    printf("%d", count);
    return 0;
}
