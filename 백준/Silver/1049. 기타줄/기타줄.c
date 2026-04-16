#include <stdio.h>
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b;
    int min1 = 1001, min6 = 1001;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        min6 = (min6 > a) ? a : min6;
        min1 = (min1 > b) ? b : min1;
    }
    int res = min1 * n;
    res = (res < min6 * ((n + 5) / 6)) ? res : (min6 * ((n + 5) / 6));
    res = (res < (min6 * (n / 6) + min1 * (n % 6))) ? res : (min6 * (n / 6) + min1 * (n % 6));
    printf("%d", res);
    return 0;
}
