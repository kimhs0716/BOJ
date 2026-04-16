#include <stdio.h>
int main(){
    int a, m = 0;
    scanf("%d", &a);
    while(a != 1){
        m = a % 2;
        a /= 2;
        if(m == 1) break;
    }
    printf("%d", !m);
    return 0;
}
