#include <stdio.h>
int main(){
    int a;
    int s = 0;
    while(scanf("%d", &a) != EOF){
        s += (a > 0);
    }
    printf("%d", s);
    return 0;
}
