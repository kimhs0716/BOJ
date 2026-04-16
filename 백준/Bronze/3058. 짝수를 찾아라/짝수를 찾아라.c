#include <stdio.h>
int main() {
    int a, m, s, n;
    scanf("%d", &n);
    for(int k = 0; k < n; k++){
        s = 0, m = 100;
        for(int i = 0; i < 7; i++){
            scanf("%d", &a);
            if(a % 2 == 0){
                m = (m > a) ? a : m;
                s += a;
            }
        }
    printf("%d %d\n", s, m);
    }
    return 0;
}
