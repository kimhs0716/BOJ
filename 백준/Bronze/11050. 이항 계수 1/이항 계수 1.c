#include <stdio.h>
int c(int n, int r){
    int res = 1;
    for(int i = 0; i < r; i++){
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", c(a, b));
    return 0;
}
