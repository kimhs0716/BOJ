#include <stdio.h>
int min(int a, int b){
    return (a > b) ? b : a;
}
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", min(b, c) + min(a - b, a - c));
    return 0;
}
