#include <stdio.h>
int main() {
    int a, b, c, d;
    scanf("%d %d", &a ,&b);
    c = (a + b) / 2;
    d = (a - b) / 2;
    if((a + b) % 2 || a < b) printf("-1");
    else
        printf("%d %d", (c > d) ? c : d, (c > d) ? d : c);
    return 0;
}
