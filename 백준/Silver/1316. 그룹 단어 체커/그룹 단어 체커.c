#include <stdio.h>
#include <string.h>
int isgroup(char *str){
    char temp[26] = {0, };
    int count = 1;
    char t = str[0];
    temp[0] = t;
    if(strlen(str) == 1) return 1;
    for(int i = 1; str[i]; i++){
        if(str[i] == t) continue;
        for(int j = 0; j < 26; j++) if(str[i] == temp[j]) return 0;
        temp[count++] = t;
        t = str[i];
    }
    return 1;
}
int main(){
    int n;
    char str[100];
    int count = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        count += isgroup(str);
    }
    printf("%d", count);
    return 0;
}
