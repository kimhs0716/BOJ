#include <stdio.h>
typedef long long int lld;
int main(){
    int n, min;
    scanf("%d", &n);
    int road[n - 1];
    int price[n - 1];
    for(int i = 0; i < n - 1; i++)
        scanf("%d", &road[i]);
    scanf("%d", &min);
    for(int i = 0; i < n - 1; i++)
        scanf("%d", &price[i]);
    lld res = 0;
    for(int i = 0; i < n - 1; i++){
        res += (lld)min * road[i];
        if(min > price[i]){
            min = price[i];
        }
    }
    printf("%lld\n", res);
    return 0;
}
