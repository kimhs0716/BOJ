#include <stdio.h>
int check(int n){
    while(n >= 666){
        if(n % 1000 == 666) return 1;
        n /= 10;
    }
    return 0;
}
int main() {
    int n, count = 0, i = 0;
    scanf("%d", &n);
    while(count < n)
        if(check(++i)) count++;
    printf("%d", i);
    return 0;
}
