#include <stdio.h>
long long int cache[80];
int main(){
    cache[0] = 1;
    cache[1] = 1;
    int n;
    scanf("%d", &n);
    if(n == 1){
        printf("%d", 4);
        return 0;
    }
    for(int i = 2; i < n; i++){
        cache[i] = cache[i - 1] + cache[i - 2];
    }
    printf("%lld", 4 * cache[n - 1] + 2 * cache[n - 2]);
    return 0;
}
