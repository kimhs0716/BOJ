#include <stdio.h>
int main(){
    int n, c = 0;
    scanf("%d", &n);
    int i;
    for(i = 1; i <= n; i++)
        if(i * (i + 1) + 1 == n)
            break;
    printf("%d", i);
    return 0;
}
