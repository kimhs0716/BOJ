#include <stdio.h>
void bin(long long int n){
    if(n == 0) return;
    bin(n / 2);
    printf("%d", n % 2);
}
int main(){
    long long int n;
    scanf("%lld", &n);
    bin(n);
    return 0;
}
