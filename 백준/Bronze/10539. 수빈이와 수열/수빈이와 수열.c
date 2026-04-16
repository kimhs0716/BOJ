#include <stdio.h>
int main(){
    int n, a, p = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        printf("%d ", a * (i + 1) - p * i);
        p = a;
    }
    return 0;
}
