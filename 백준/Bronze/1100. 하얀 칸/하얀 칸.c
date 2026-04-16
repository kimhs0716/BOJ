#include <stdio.h>
int main(){
    int c = 0;
    char chr;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++){
            scanf(" %c", &chr);
            if(chr == 'F' && (i + j) % 2 == 0) c++;
        }
    printf("%d", c);
    return 0;
}
