#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    long long int a = 0, b = 1;
    while(n--){
        long long int t = a;
        a = b;
        b += 2 * t;
        a %= 10007;
        b %= 10007;
    }
    printf("%lld", b);
    return 0;
}
