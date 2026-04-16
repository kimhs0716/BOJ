#include <stdio.h>
int main(){
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    printf("%d\n%d\n%d", d - a - 1 + (b * 100 + c <= e * 100 + f), d - a + 1, d - a);
    return 0;
}
