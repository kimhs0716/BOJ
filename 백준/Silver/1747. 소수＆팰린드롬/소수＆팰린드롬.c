#include <stdio.h>
#include <math.h>
int isprime(int n){
    if(n < 2) return 0;
    if(n == 2) return 1;
    if(n == 3) return 1;
    if(n % 2 == 0) return 0;
    double loop = pow((double)n, 0.5);
    for(int i = 3; i < loop + 1; i += 2){
        if(n % i == 0) return 0;
    }
    return 1;
}
int rev(int n){
    int res = 0;
    while(n){
        res *= 10;
        res += n % 10;
        n /= 10;
    }
    return res;
}
int ispal(int n){
    return n == rev(n);
}
int main(){
    int n;
    scanf("%d", &n);
    if(n == 1 || n == 2){
        printf("2\n");
        return 0;
    }
    if(n % 2 == 0) n++;
    for(;!(ispal(n) && isprime(n)); n += 2);
    printf("%d\n", n);
    return 0;
}
