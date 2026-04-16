#include <stdio.h>
int main(){
    int a, b, c;
    while(1){
        c = scanf("%d %d", &a, &b);
        if(c == EOF) break;
        printf("%d\n", a + b);
    }
    return 0;
}