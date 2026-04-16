#include <stdio.h>
int rev(int n){
    int res = 0;
    while(n){
        res *= 10;
        res += n % 10;
        n /= 10;
    }
    return res;
}
int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d", rev(rev(x) + rev(y)));
    return 0;
}
