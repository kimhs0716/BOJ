#include <stdio.h>
int main(){
    int a, b, c, d, e, f;
    scanf("%d:%d:%d", &d, &e, &f);
    scanf("%d:%d:%d", &a, &b, &c);
    c -= f;
    if(c < 0){
        c += 60;
        b--;
    }
    b -= e;
    if(b < 0){
        b += 60;
        a--;
    }
    a -= d;
    if(a < 0) a += 24;
    if(a == b && b == c && a == 0) a = 24;
    printf("%02d:%02d:%02d", a, b, c);
    return 0;
}
