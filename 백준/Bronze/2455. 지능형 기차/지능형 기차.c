#include <stdio.h>
int main() {
    int a, b, t = 0, m = 0;
    for(int i = 0; i < 4; i++){
        scanf("%d %d", &a, &b);
        t += -a + b;
        m = (m < t) ? t : m;
    }
    printf("%d", m);
    return 0;
}
