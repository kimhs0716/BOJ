#include <stdio.h>
#include <string.h>
int ispal(char *str, int len){
    for(int i = 0; i <= len / 2; i++){
        if(str[i] != str[len - i - 1]) return 0;
    }
    return 1;
}
int main(){
    char str[500001];
    scanf("%s", str);
    int len = strlen(str);
    int isall = 1;
    char a0 = str[0];
    for(int i = 0; i < len; i++)
        if(str[i] != a0){
            isall = 0;
            break;
        }
    if(isall){
        printf("-1");
        return 0;
    }
    if(ispal(str, len)){
        printf("%d", len - 1);
        return 0;
    }
    printf("%d", len);
    return 0;
}
