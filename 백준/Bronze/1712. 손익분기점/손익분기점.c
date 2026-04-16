#include <stdio.h>
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(b >= c) printf("-1");
    else printf("%d", (int)((double)a / (c - b)) + 1);
    return 0;
}
