#include <stdio.h>
int find(char* str, char c);
int main(){
    int res;
    char str[100];
    scanf("%s", str);
    for(char i = 'a'; i <= 'z'; i++) printf("%d ", find(str, i));
    return 0;
}

int find(char* str, char c){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == c) return i;
        i++;
    }
    return -1;
}
