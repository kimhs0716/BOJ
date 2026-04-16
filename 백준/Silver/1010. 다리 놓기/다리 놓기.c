#include <stdio.h>
int c(int n, int r){
    int res = 1;
    for(int i = 0; i < r; i++){
        //printf("%d %d %d\n", res, n, i);
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
int main(){
    int t, a, b;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", c(b, a));
    }
    return 0;
}
