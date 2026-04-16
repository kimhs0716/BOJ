#include <stdio.h>
int main(){
    int n, m, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < 5; i++){
        scanf("%d", &m);
        if(n == m) sum++;
    }
    printf("%d\n", sum);
    return 0;
}
