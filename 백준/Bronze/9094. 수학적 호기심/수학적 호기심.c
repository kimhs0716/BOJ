#include <stdio.h>
int main(){
    int t, n, m, s;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
        scanf("%d %d", &n, &m);
        s = 0;
        for(int a = 1; a < n; a++){
            for(int b = a + 1; b < n; b++){
                if((a * a + b * b + m) % (a * b) == 0) s++;
            }
        }
        printf("%d\n", s);
    }
    return 0;
}
