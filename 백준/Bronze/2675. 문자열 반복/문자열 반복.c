#include <stdio.h>
int main(){
    int a, r;
    char str[20];
    scanf("%d", &a);
    for(int i = 0; i < a; i++){
        scanf("%d ", &r);
        scanf("%s", str);
        int j = 0;
        while(str[j] != '\0'){
            for(int k = 0; k < r; k++) printf("%c", str[j]);
            j++;
        }
        printf("\n");
    }
    return 0;
}
