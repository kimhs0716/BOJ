#include <stdio.h>

int main(){
    int n, a, b;
    scanf("%d", &n);
    a = n / 5;
    b = 0;
    while(1){
        while(a * 5 + b * 3 < n) b++;
        if(a * 5 + b * 3 == n){
            printf("%d", a + b);
            break;
        }
        a -= 1;
        b += 1;
        if(a < 0){
            printf("-1");
            break;
        }
    }
    return 0;
}
