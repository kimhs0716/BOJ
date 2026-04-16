#include <stdio.h>

int main(){
    long long int x;
    long long int n = 0;
    scanf("%lld", &x);
    while(x > 0) x -= ++n;
    x += n;
    if(n % 2 == 1){
        printf("%lld/%lld", n + 1 - x, x);
    }
    else printf("%lld/%lld", x, n + 1 - x);
    return 0;
}
