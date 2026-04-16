#include <stdio.h>
int main(){
    int n, t = 0, a, c = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        if(a == t){
            c++;
            t = (t + 1) % 3;
        }
    }
    printf("%d", c);
    return 0;
}
