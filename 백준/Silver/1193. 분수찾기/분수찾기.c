#include <stdio.h>

int main(){
    int x;
    int temp = 0, n = 0;
    scanf("%d", &x);
    while(x > 0) x -= ++n;
    x += n;
    if(n % 2 == 1){
        printf("%d/%d", n + 1 - x, x);
    }
    else printf("%d/%d", x, n + 1 - x);
    return 0;
}
