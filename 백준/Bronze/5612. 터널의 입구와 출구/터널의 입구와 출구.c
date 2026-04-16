#include <stdio.h>
int main(){
    int t, c, a, b, m;
    scanf("%d %d", &t, &c);
    m = c;
    for(int i = 0; i < t; i++){
        scanf("%d %d", &a, &b);
        c += a - b;
        if(c < 0){
            printf("0");
            return 0;
        }
        m = (c < m) ? m : c;
    }
    printf("%d", m);
    return 0;
}
