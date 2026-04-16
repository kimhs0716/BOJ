#include <stdio.h>
int main(){
    int k;
    scanf("%d", &k);
    int a = 1, b = 0;
    while(k--){
        int t = b;
        b = b + a;
        a = t;
    }
    printf("%d %d", a, b);
    return 0;
}
