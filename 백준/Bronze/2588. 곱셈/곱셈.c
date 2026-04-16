#include <stdio.h>
int main(){
    int a, b, res;
    scanf("%d %d", &a, &b);
    res = a * b;
    while(b != 0){
        printf("%d\n", a * (b % 10));
        b /= 10;
    }
    printf("%d", res);
    return 0;
}
