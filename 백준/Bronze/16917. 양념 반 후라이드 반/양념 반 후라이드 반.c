#include <stdio.h>
int main(){
    int a, b, c, x, y, d = 0, e = 0, f = 0;
    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
    if(0.5 * a + 0.5 * b > c) f = ((x < y) ? x : y) * 2;
    x -= f / 2;
    y -= f / 2;
    //printf("%d %d %d %d %d\n", d, e, f, x, y);
    if(y != 0){
        if(b < 2 * c) e = y;
        else f += 2 * y;
    }
    if(x != 0){
        if(a < 2 * c) d = x;
        else f += 2 * x;
    }
    //printf("%d %d %d\n", d, e, f);
    printf("%d", a * d + b * e + c * f);
    return 0;
}
