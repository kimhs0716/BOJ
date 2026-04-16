#include <stdio.h>
int main() {
    int n, a, s = 0, t = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        if(a == 1){
            t++;
            s += t;
        }
        else t = 0;
    }
    printf("%d", s);
    return 0;
}
