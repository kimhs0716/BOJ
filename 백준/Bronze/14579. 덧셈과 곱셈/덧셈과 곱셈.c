#include <stdio.h>
int main() {
    int a, b, res = 1;
    scanf("%d %d", &a, &b);
    int s = (a * (a + 1) / 2) % 14579;
    for(int i = a + 1; i <= b + 1; i++){
        res *= s;
        s += i;
        res %= 14579;
    }
    printf("%d", res);
    return 0;
}
