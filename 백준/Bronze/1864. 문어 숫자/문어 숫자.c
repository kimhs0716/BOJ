#include <stdio.h>
int main(){
    char str[9];
    int res;
    while(1){
        res = 0;
        scanf("%s", str);
        if(str[0] == '#') break;
        for(int i = 0; str[i]; i++){
            res *= 8;
            switch(str[i]){
                case '\\':
                    res += 1;
                    break;
                case '(':
                    res += 2;
                    break;
                case '@':
                    res += 3;
                    break;
                case '?':
                    res += 4;
                    break;
                case '>':
                    res += 5;
                    break;
                case '&':
                    res += 6;
                    break;
                case '%':
                    res += 7;
                    break;
                case '/':
                    res--;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
