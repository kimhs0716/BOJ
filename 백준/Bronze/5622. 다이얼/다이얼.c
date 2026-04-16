#include <stdio.h>
#include <string.h>
int time(char c){
    if(c < 'S') return (c - 'A') / 3 + 3;
    else if(c == 'S') return 8;
    else if(c <= 'V') return 9;
    else return 10;
}
int main(){
    char c[15];
    int t = 0, i = 0;
    scanf("%s", c);
    while(c[i] != '\0'){
        t += time(c[i]);
        i++;
    }
    printf("%d", t);
    return 0;
}
