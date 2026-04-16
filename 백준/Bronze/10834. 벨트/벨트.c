#include <stdio.h>
int main(){
    int a = 1, b = 0;
    int n, c, d, e;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &c, &d, &e);
        if(e) b = (!b);
        a = (int)((double)a / c * d);
    }
    printf("%d %d", b, a);
    return 0;
}
