#include <stdio.h>
#include <string.h>
int main(){
    int n, len;
    char res[51], inp[51];
    scanf("%d", &n);
    scanf("%s", res);
    len = strlen(res);
    for(int i = 0; i < n - 1; i++){
        scanf("%s", inp);
        for(int j = 0; j < len; j++){
            if(res[j] != inp[j]) res[j] = '?';
        }
    }
    printf("%s", res);
    return 0;
}
