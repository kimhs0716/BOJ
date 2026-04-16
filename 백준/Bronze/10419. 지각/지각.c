#include <stdio.h>
int main(){
    int t, n, i;
    scanf("%d", &t);
    for(int j = 0; j < t; j++){
        i = 0;
        scanf("%d", &n);
        for(; i * (i + 1) <= n; i++);
        printf("%d\n", i - 1);
    }
    return 0;
}
