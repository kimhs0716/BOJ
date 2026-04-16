#include <stdio.h>
int main() {
    int n, a, b, s1 = 100, s2 = 100;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        if(a < b) s1 -= b;
        else if(a > b) s2 -= a;
    }
    printf("%d\n%d", s1, s2);
    return 0;
}
