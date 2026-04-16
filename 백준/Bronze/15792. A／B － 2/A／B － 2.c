#include <stdio.h>
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int i = 0;
    printf("%d", a / b);
    if(a % b == 0) return 0;
    printf(".");
    a %= b;
    while(a != 0 && i < 1000){
        a *= 10;
        printf("%d", a / b);
        a %= b;
        i++;
    }
    return 0;
}
