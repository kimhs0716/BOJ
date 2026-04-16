#include <stdio.h>
int main(){
    int a, b, c, res;
    scanf("%d %d %d", &a, &b, &c);
    if(a < b) res = b;
    else if(a > c) res = c;
    else res = a;
    printf("%d", res);
    return 0;
}
