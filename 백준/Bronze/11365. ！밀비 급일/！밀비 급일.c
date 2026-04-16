#include <stdio.h>
#include <string.h>
void reverse(char *str, int len);
int main(){
    char str[501];
    while(1){
        scanf(" %[^\n]s", str);
        if(!strcmp(str, "END")) break;
        reverse(str, strlen(str));
    }
    return 0;
}

void reverse(char *str, int len){
    for(int i = len - 1; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
    return;
}
