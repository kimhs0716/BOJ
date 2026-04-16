#include <stdio.h>
int cache[10];
int joy(int n){
    if(n == 1) return 0;
    if(n % 2 == 0) return (n / 2) * (n / 2) + 2 * joy(n / 2);
    else return (n / 2) * (n / 2 + 1) + joy(n / 2) + joy(n / 2 + 1);
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d", joy(n));
    return 0;
}
