#include <stdio.h>
int main(){
    int k, n, t, time = 210;
    char z;
    scanf("%d %d", &k, &n);
    k--;
    for(int i = 0; i < n; i++){
        //printf("%d\n", k);
        scanf("%d %c", &t, &z);
        time -= t;
        if(time <= 0) break;
        if(z != 'T') continue;
        k = (k + 1) % 8;
    }
    printf("%d", k + 1);
    return 0;
}
