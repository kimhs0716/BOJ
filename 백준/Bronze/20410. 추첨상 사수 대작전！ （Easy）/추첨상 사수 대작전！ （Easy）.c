#include <stdio.h>
int main() {
    int m, s, x1, x2;
    scanf("%d %d %d %d", &m, &s, &x1, &x2);
    for(int a = 0; a < m; a++){
        for(int c = 0; c < m; c++){
            if(x1 == (a * s + c) % m && x2 == (a * x1 + c) % m){
                printf("%d %d", a, c);
                return 0;
            }
        }
    }
    return 0;
}
