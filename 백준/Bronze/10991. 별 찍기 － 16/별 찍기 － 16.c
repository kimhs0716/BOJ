#include <stdio.h>
int main() {
    int a;
    scanf("%d", &a);
    for(int i = a - 1; i >= 0; i--){
        for(int j = 0; j < i; j++) printf(" ");
        for(int j = a - i; j > 0; j--) printf("* ");
        printf("\n");
    }
    return 0;
}
