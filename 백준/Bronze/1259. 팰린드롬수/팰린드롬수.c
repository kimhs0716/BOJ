#include <stdio.h>
int reversed(int n){
    int res = 0;
    while(n){
        res *= 10;
        res += n % 10;
        n /= 10;
    }
    return res;
}
int ispal(int n){
    return n == reversed(n);
}
int main(){
    int n;
    while(1){
        scanf("%d", &n);
        if(n == 0) break;
        printf(ispal(n) ? "yes\n" : "no\n");
    }
    return 0;
}
