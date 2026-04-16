#include <stdio.h>
int main() {
    char str[51], pre;
    scanf("%s", str);
    int i = 1, res = 10;
    pre = str[0];
    while(str[i]){
        if(str[i] == pre) res += 5;
        else{
            pre = str[i];
            res += 10;
        }
        i++;
    }
    printf("%d", res);
    return 0;
}
