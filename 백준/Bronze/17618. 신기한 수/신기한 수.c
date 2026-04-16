#include <stdio.h>
int sum(int n){
    int s = 0;
    while(n){
        s += n % 10;
        n /= 10;
    }
    return s;
}
int main(){
    int n, c = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        c += !(i % sum(i));
    printf("%d", c);
    return 0;
}
