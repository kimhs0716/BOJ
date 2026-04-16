#include <stdio.h>
int main() {
    int a, b, c;
    scanf("%d %d", &a, &b);
    c = a * 100 + b;
    if(c < 218) printf("Before");
    else if(c == 218) printf("Special");
    else printf("After");
    return 0;
}
