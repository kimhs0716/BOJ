#include <stdio.h>
int gcd2(int, int);
int main(){
    int a, b, gcd, lcm;
    scanf("%d %d", &a, &b);
    gcd = gcd2(a, b);
    lcm = a * b / gcd;
    printf("%d\n%d", gcd, lcm);
    return 0;
}
int gcd2(int a, int b){
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
