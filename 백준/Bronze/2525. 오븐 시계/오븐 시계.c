#include <stdio.h>
int main(){
    int a, b, c;
    scanf("%d %d\n%d", &a, &b, &c);
    b += c;
    a += b / 60;
    b %= 60;
    a %= 24;
    printf("%d %d\n", a, b);
    return 0;
}
