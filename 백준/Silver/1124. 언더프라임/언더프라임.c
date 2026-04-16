#include <stdio.h>
#include <math.h>
int isprime(int n){
    if(n < 2) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    double loop = pow((double)n, 0.5);
    for(int i = 3; i <= loop; i += 2)
        if(n % i == 0) return 0;
    return 1;
}
int isunderprime(int n){
    int c = 0;
    while(n % 2 == 0){
        n /= 2;
        c++;
    }
    int i = 3;
    while(n != 1){
        if(n % i == 0){
            c++;
            n /= i;
            i -= 2;
        }
        i += 2;
    }
    return isprime(c);
}
int main(){
    int c = 0;
    int a, b;
    scanf("%d %d", &a, &b);
    for(int i = a; i <= b; i++)
        if(isunderprime(i)) c++;
    printf("%d", c);
    return 0;
}
