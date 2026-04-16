#include <stdio.h>
#include <string.h>
int reverse(int n){
    int res = (n % 10) * 100;
    n /= 10;
    res += n % 10 * 10;
    n /= 10;
    res += n;
    return res;
}
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    a = reverse(a);
    b = reverse(b);
    printf("%d", (a < b) ? b : a);
    return 0;
}
