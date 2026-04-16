#include <stdio.h>
int main() {
    int a, b, c, d;
    scanf("%d %d %d", &a, &b, &c);
    for(int i = 0; i < a; i++){
        scanf("%d", &d);
        if(d * d <= b * b + c * c) printf("DA\n");
        else printf("NE\n");
    }
    return 0;
}
