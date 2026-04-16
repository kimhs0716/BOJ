#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    int count = 0;
    int i = 0;
    scanf("%s", str);
    while(str[i]){
        count++;
        if(str[i] == '=' && i >= 1 && (str[i - 1] == 'c' || str[i - 1] == 's')) count--;
        if(str[i] == '=' && i >= 1 && str[i - 1] == 'z') {
            if(str[i] == '=' && i >= 2 && str[i - 1] == 'z' && str[i - 2] == 'd') count--;
            count--;
        }
        if(str[i] == '-' && i >= 1 && (str[i - 1] == 'c' || str[i - 1] == 'd')) count--;
        if(str[i] == 'j' && i >= 1 && (str[i - 1] == 'l' || str[i - 1] == 'n')) count--;
        i++;
    }
    printf("%d", count);
    return 0;
}
