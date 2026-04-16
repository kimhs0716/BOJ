#include <stdio.h>
int main() {
    int n, t, a, c = 0;
    scanf("%d %d", &n, &t);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        t -= a;
        c++;
        if(t < 0){
            c--;
            break;
        }
    }
    printf("%d", c);
    return 0;
}
