#include <stdio.h>
int main() {
    int a, b;
    scanf("%d", &a);
    if(a % 10 == 0){
        b = a / 100;
        a %= 100;
    }
    else{
        b = a / 10;
        a %= 10;
    }
    printf("%d", a + b);
    return 0;
}
