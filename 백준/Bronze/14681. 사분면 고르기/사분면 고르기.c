#include <stdio.h>
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    if(a > 0) printf((b > 0) ? "1" : "4");
    else printf((b > 0) ? "2" : "3");
    return 0;
}
