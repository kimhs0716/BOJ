#include <stdio.h>
int main(){
    int a, b, c, d, e;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    e = (b / d) * (c / d);
    printf("%d", (a > e) ? e : a);
    return 0;
}
