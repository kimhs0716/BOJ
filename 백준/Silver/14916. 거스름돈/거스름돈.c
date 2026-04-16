#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    if(n == 1 || n == 3){
        printf("-1");
        return 0;
    }
    int f = n / 5;
    n %= 5;
    if(n % 2 == 0){
        printf("%d", f + n / 2);
        return 0;
    }
    f--;
    n += 5;
    printf("%d", f + n / 2);
    return 0;
}
