#include <stdio.h>
long long int cache[36] = {1, };
long long int t(int n){
    if(cache[n] == 0){
        long long int s = 0;
        for(int i = 0; i < n; i++){
            s += t(i) * t(n - i - 1);
        }
        cache[n] = s;
    }
    return cache[n];
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%lld", t(n));
    return 0;
}
