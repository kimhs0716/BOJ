#include <stdio.h>

int main(){
    int a, b, v, d, c;
    scanf("%d %d %d", &a, &b, &v);
    if(a >= v) d = 1;
    else{
        c = v - a;
        d = c / (a - b) + (c % (a - b) != 0) + 1;
    }
    printf("%d", d);
    return 0;
}
