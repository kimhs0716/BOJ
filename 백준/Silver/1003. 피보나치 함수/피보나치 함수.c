#include<stdio.h>
int cache[41][2];
int main() {
    for(int i = 0; i < 41; i++){
        cache[i][0] = cache[i][1] = 0;
    }
    cache[0][0] = cache[1][1] = 1;
    int n, t, zero, one;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        zero = one = 0;
        scanf("%d", &n);
        for(int j = 2; j <= n; j++){
            cache[j][0] = cache[j - 1][0] + cache[j - 2][0];
            cache[j][1] = cache[j - 1][1] + cache[j - 2][1];
        }
        printf("%d %d\n", cache[n][0], cache[n][1]);
    }
    /*printf("\n============\n");
    for(int i = 0; i < 41; i++){
        printf("%d: %d %d\n", i, cache[i][0], cache[i][1]);
    }*/
    return 0;
}
