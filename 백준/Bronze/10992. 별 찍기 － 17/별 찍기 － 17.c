#include <stdio.h>
int main() {
    int a;
    scanf("%d", &a);
    for(int i = 0; i < a - 1; i++) printf(" ");
    printf("*\n");
    for(int i = a - 2; i >= 1; i--){
        for(int j = 0; j < i; j++) printf(" ");
        printf("*");
        for(int j = 2 * (a - i) - 3; j > 0; j--) printf(" ");
        printf("*\n");
    }
    if(a != 1)
        for(int i = 0; i < 2 * a - 1; i++) printf("*");
    return 0;
}
