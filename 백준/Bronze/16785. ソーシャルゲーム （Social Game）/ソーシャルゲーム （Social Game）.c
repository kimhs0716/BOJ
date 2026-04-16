#include <stdio.h>
int main(){
    int a, b, c ,d = 0, t = 0;
    scanf("%d %d %d", &a, &b, &c);
    while(1){
        if(t >= c) break;
        d++;
        if(d % 7 == 0) t += b;
        t += a;
    }
    printf("%d", d);
    return 0;
}
