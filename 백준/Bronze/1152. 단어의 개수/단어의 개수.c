#include <stdio.h>
#include <string.h>
int main(){
    char str[1000000];
    int count = 0;
    char *ptr;
    scanf("%[^\n]s", str);
    ptr = strtok(str, " ");
    while(ptr != NULL){
        ptr = strtok(NULL, " ");
        count++;
    }
    printf("%d", count);
    return 0;
}
