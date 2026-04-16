#include <stdio.h>
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    b -= 45;
    a -= (b < 0) ? 1 : 0;
    b += (b < 0) ? 60 : 0;
    a += (a < 0) ? 24 : 0;
    printf("%d %d", a, b);
    return 0;
}
