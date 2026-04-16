#include <stdio.h>

int main(){
    int n, i = 2;
    scanf("%d", &n);
    while(n != 1){
        if(n % i == 0){
            n /= i;
            printf("%d\n", i);
            continue;
        }
        i++;
    }
    return 0;
}
