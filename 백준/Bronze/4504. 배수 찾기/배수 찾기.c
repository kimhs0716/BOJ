#include <stdio.h>
int main() {
    int n, a;
    scanf("%d", &n);
    while(1){
        scanf("%d", &a);
        if(a == 0) break;
        printf("%d is", a);
        if(a % n != 0) printf(" NOT");
        printf(" a multiple of %d.\n", n);
    }
    return 0;
}
