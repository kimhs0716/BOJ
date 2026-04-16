#include <stdio.h>
int main() {
    int a, b, count = 0, i = 1;
    scanf("%d %d", &a, &b);
    while(1){
        if(a % i++ == 0) count++;
        if(count == b){
            printf("%d", --i);
            break;
        }
        if(i > a){
            printf("0");
            break;
        }
    }
    return 0;
}
