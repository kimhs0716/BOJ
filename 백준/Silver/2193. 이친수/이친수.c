#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    long long int a = 0, b = 1;
    n--;
    while(n--){
        long long int t = a;
        a = b;
        b += t;
    }
    printf("%lld", b);
    return 0;
}
