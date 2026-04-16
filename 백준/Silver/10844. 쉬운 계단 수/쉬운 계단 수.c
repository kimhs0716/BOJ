#include <stdio.h>
int cache[100][10];
int main(){
    for(int i = 1; i < 10; i++)
        cache[0][i] = 1;
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        cache[i][0] = cache[i - 1][1];
        cache[i][9] = cache[i - 1][8];
        for(int j = 1; j <= 8; j++)
            cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j + 1]) % 1000000000;
    }
    int s = 0;
    for(int i = 0; i < 10; i++){
        s += cache[n - 1][i];
        s %= 1000000000;
    }
    printf("%d\n", s % 1000000000);
    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++)
            printf("%-10d", cache[i][j] % 1000000000);
        printf("\n");
    }
    */
    return 0;
}
