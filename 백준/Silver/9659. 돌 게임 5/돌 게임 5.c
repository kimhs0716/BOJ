#include <stdio.h>
int main(){
    long long int n;
    scanf("%lld", &n);
    printf((n % 2) ? "SK" : "CY");
    return 0;
}
