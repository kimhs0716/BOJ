#include <stdio.h>
int main(){
    int a, b, c;
    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if(a == b) break;
        if(a - b == b - c) printf("AP %d\n", 2 * c - b);
        else printf("GP %d\n", c * c / b);
    }
    return 0;
}
