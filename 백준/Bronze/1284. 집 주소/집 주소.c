#include <stdio.h>
int main(){
    int n;
    while(1){
        int s = 1;
        scanf("%d", &n);
        if(n == 0) break;
        while(n){
            if(n % 10 == 1) s += 2;
            else if(n % 10 == 0) s += 4;
            else s += 3;
            s += 1;
            n /= 10;
        }
        printf("%d\n", s);
    }
    return 0;
}
