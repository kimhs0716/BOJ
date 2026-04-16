#include <stdio.h>
int max(int a, int b, int c){
    if(a < c && b < c) return c;
    if(b < a && c < a) return a;
    return b;
}
int min(int a, int b, int c){
    if(a > c && b > c) return c;
    if(b > a && c > a) return a;
    return b;
}
void d(int a, int b, int c){
    int M, m, mid;
    M = max(a, b, c);
    m = min(a, b, c);
    mid = a + b + c - M - m;
    if(M * M == m * m + mid * mid) printf("yes\n");
    else printf("no\n");
}
int main(){
    int a, b, c, n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d", &a, &b, &c);
        printf("Scenario #%d:\n", i);
        d(a, b, c);
        printf("\n");
    }
}
