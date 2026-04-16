#include <stdio.h>
int main(){
    int n, a = 0, b = 0, ta, tb;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &ta, &tb);
        if(ta > tb) a++;
        if(ta < tb) b++;
    }
    printf("%d %d", a, b);
    return 0;
}