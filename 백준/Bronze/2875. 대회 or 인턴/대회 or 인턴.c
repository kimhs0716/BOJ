#include <stdio.h>
int main() {
    int a, b, c, t = 0;
    scanf("%d %d %d", &a, &b, &c);
    while(1){
        t++;
        a -= 2;
        b--;
        if(a + b < c || a < 0 || b < 0){
            t--;
            break;
        }
    }
    printf("%d", t);
    return 0;
}
