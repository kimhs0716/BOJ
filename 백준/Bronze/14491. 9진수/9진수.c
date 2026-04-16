#include <stdio.h>
void nine(int n){
    if(n == 0) return;
    nine(n / 9);
    printf("%d", n % 9);
}
int main(){
    int n;
    scanf("%d", &n);
    nine(n);
    return 0;
}
