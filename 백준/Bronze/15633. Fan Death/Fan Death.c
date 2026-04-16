#include <stdio.h>
int sum(int n){
    int s = 0;
    for(int i = 1; i <= n; i++)
        if(n % i == 0) s += i;
    return s;
}
int main(){
    int n, c = 0;
    scanf("%d", &n);
    printf("%d", sum(n) * 5 - 24);
    return 0;
}
