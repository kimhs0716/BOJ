#include <stdio.h>
int gcd(int a, int b){
    int r;
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int lcm(int a, int b){
    return a * b / gcd(a, b);
}
int lcm3(int a, int b, int c){
    return lcm(lcm(a, b), c);
}
int main(){
    int a, b, c, d, e;
    int m;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    m = lcm3(a, b, c);
    m = (m < lcm3(a, b, d)) ? m : lcm3(a, b, d);
    m = (m < lcm3(a, b, e)) ? m : lcm3(a, b, e);
    m = (m < lcm3(a, c, d)) ? m : lcm3(a, c, d);
    m = (m < lcm3(a, c, e)) ? m : lcm3(a, c, e);
    m = (m < lcm3(a, d, e)) ? m : lcm3(a, d, e);
    m = (m < lcm3(b, c, d)) ? m : lcm3(b, c, d);
    m = (m < lcm3(b, c, e)) ? m : lcm3(b, c, e);
    m = (m < lcm3(b, d, e)) ? m : lcm3(b, d, e);
    m = (m < lcm3(c, d, e)) ? m : lcm3(c, d, e);
    printf("%d", m);
    return 0;
}
