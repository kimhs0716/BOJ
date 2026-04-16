#include <stdio.h>
int main(){
    int n, a, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        sum += a;
    }
    if(n * sum) printf("1.00");
    else printf("divide by zero");
    return 0;
}
