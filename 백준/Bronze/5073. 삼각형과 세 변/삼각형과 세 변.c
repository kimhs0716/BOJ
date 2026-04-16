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
    if(a == b && b == c){
        printf("Equilateral\n");
        return;
    }
    int M, m, mid;
    M = max(a, b, c);
    m = min(a, b, c);
    mid = a + b + c - M - m;
    if(M >= m + mid){
        printf("Invalid\n");
        return;
    }
    if(a == b || b == c || c == a){
        printf("Isosceles\n");
        return;
    }
    printf("Scalene\n");
}
int main(){
    int a, b, c;
    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0) break;
        d(a, b, c);
    }
}
