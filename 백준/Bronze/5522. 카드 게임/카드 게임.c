#include <stdio.h>
int main(){
    int n, s = 0;
    for(int i = 0; i < 5; i++){
        scanf("%d", &n);
        s += n;
    }
    printf("%d\n", s);
    return 0;
}