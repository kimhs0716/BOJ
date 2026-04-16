#include <stdio.h>
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a + b == c){
        printf("%d+%d=%d", a, b, c);
        return 0;
    }
    if(a - b == c){
        printf("%d-%d=%d", a, b, c);
        return 0;
    }
    if(a * b == c){
        printf("%d*%d=%d", a, b, c);
        return 0;
    }
    if((double)a / b == c){
        printf("%d/%d=%d", a, b, c);
        return 0;
    }
    if(a == b + c){
        printf("%d=%d+%d", a, b, c);
        return 0;
    }
    if(a == b - c){
        printf("%d=%d-%d", a, b, c);
        return 0;
    }
    if(a == b * c){
        printf("%d=%d*%d", a, b, c);
        return 0;
    }
    printf("%d=%d/%d", a, b, c);
    return 0;
}
