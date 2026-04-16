#include <stdio.h>
int main(){
    int n, i = 0;
    scanf("%d", &n);
    while(1){
        i++;
        if(n == 1) break;
        if(n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
    }
    printf("%d", i);
    return 0;
}
