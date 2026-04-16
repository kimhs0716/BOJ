#include <stdio.h>
int main() {
    int a, m = 100, s = 0;
    for(int i = 0; i < 7; i++){
        scanf("%d", &a);
        if(a % 2){
            m = (m > a) ? a : m;
            s += a;
        }
    }
    if(s){
        printf("%d\n%d", s, m);
    }
    else printf("-1");
    return 0;
}
