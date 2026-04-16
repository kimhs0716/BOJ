#include <stdio.h>
int main(){
    int a = 0, t, m, c, d;
    scanf("%d %d", &c, &d);
    m = 0;
    for(int i = 0; i < c; i++){
        scanf("%d", &t);
        m = (m < t) ? t : m;
    }
    a += m;
    m = 0;
    for(int i = 0; i < d; i++){
        scanf("%d", &t);
        m = (m < t) ? t : m;
    }
    a += m;
    printf("%d", a);
    return 0;
}
