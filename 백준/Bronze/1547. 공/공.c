#include <stdio.h>
int main() {
    int a, b, c = 1, n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        if(a == c) c = b;
        else if(b == c) c = a;
    }
    printf("%d", c);
    return 0;
}
