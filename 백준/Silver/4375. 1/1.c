#include <stdio.h>
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int res = 1, cnt = 1;
        while(res % n){
            res = 10 * res + 1;
            res %= n;
            cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}