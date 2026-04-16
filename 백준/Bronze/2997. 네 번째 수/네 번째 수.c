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
    if(M - mid == mid - m){
        printf("%d", 2 * M - mid);
        return;
    }
    if(M - mid == 2 * (mid - m)){
        printf("%d", (M + mid) / 2);
        return;
    }
    printf("%d", (m + mid) / 2);
}
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    d(a, b, c);
    return 0;
}
