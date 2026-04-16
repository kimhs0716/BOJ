#include <stdio.h>
int main(){
    int res, n;
    scanf("%d", &n);
    res = n;
    char op;
    while(1){
        scanf(" %c", &op);
        if(op == '=') break;
        scanf("%d", &n);
        if(op == '+') res += n;
        else if(op == '-') res -= n;
        else if(op == '*') res *= n;
        else res /= n;
    }
    printf("%d", res);
    return 0;
}
