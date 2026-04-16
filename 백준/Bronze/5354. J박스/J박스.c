#include <stdio.h>

int main() {
    int n, a;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        for(int j = 0; j < a; j++)
            printf("#");
        printf("\n");
        if(a == 1){
            printf("\n");
            continue;
        }
        for(int j = 0; j < a - 2; j++){
            printf("#");
            for(int k = 0; k < a - 2; k++)
                printf("J");
            printf("#\n");
        }
        for(int j = 0; j < a; j++)
            printf("#");
        printf("\n\n");
    }
    return 0;
}
