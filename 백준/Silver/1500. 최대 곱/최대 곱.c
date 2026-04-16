#include <stdio.h>
int main(){
    int s, k;
    scanf("%d %d", &s, &k);
    long long int res = 1;
    int r = s / k;
    int n = s % k;
    for(int i = 0; i < k; i++){
        res *= (r + (n > 0));
        n--;
    }
    printf("%lld", res);
    return 0;
}
