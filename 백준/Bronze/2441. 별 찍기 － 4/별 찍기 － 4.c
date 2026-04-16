#include <stdio.h>
int main() {
    int a;
    scanf("%d", &a);
    for(int i = a; i > 0; i--){
        for(int j = 0; j < a - i; j++)
            printf(" ");
        for(int j = 0; j < i; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
