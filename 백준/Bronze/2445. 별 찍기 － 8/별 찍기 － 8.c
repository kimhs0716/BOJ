#include <stdio.h>
int main() {
    int a;
    scanf("%d", &a);
    for(int i = 1; i <= a; i++){
        for(int j = 0; j < i; j++) printf("*");
        for(int j = 0; j < 2 * (a - i); j++) printf(" ");
        for(int j = 0; j < i; j++) printf("*");
        printf("\n");
    }
    for(int i = a - 1; i > 0; i--){
        for(int j = 0; j < i; j++) printf("*");
        for(int j = 0; j < 2 * (a - i); j++) printf(" ");
        for(int j = 0; j < i; j++) printf("*");
        printf("\n");
    }
    return 0;
}
