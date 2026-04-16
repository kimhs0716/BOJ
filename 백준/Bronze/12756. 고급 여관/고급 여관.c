#include <stdio.h>
int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    while(b > 0 && d > 0){
        b -= c;
        d -= a;
    }
    if(b <= 0){
        if(d <= 0) printf("DRAW");
        else printf("PLAYER B");
    }
    else printf("PLAYER A");
    return 0;
}
