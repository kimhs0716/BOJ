#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int count = 0;
    int k = 1, r = 0;
    for(int i = 1; i <= n; i++){
        if(k == i){
            r++;
            k *= 10;
        }
        count += r;
    }
    printf("%d\n", count);
    return 0;
}
