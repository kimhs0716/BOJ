#include <stdio.h>
#include <math.h>
int gcd(int a, int b){
    while(1){
        if(a == 0) return b;
        int t = a;
        a = b % a;
        b = t;
    }
}
void print_divs(int n){
    for(int i = 1; i <= n; i++)
        if(n % i == 0) printf("%d\n", i);
}
int main() {
    int n, a, b;
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    b = gcd(a, b);
    if(n == 3){
        scanf("%d", &a);
        b = gcd(a, b);
    }
    print_divs(b);
    return 0;
}
