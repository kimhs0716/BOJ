#include <stdio.h>
#include <math.h>
int main(){
    int a, b, c, d;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    c = a / 4;
    a %= 4;
    d = b / 4;
    b %= 4;
    printf("%d", abs(a - b) + abs(c - d));
    return 0;
}
