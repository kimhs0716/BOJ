#include <stdio.h>
int main() {
    int a, b, c, d, m = 0, i = 0;
    for(int j = 1; j <= 5; j++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if(m < (a + b + c + d)){
            m = a + b + c + d;
            i = j;
        }
    }
    printf("%d %d", i, m);
    return 0;
}
