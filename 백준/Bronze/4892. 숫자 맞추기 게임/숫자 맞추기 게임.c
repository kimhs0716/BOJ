#include <stdio.h>
int main(){
    int i = 0, n0, n1, n4;
    while(++i){
        scanf("%d", &n0);
        if(n0 == 0) break;
        printf("%d. ", i);
        printf((n0 % 2 == 0) ? "even " : "odd ");
        n1 = 3 * n0;
        n1 = (n1 % 2 == 0) ? n1 / 2 : (n1 + 1) / 2;
        n1 *= 3;
        n4 = n1 / 9;
        printf("%d\n", n4);
    }
}
