#include <stdio.h>
int gcd(int, int);
int lcm(int, int);
int main(){
    int t, a, b;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", lcm(a, b));
    }
    return 0;
}
int gcd(int a, int b){
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int lcm(int a, int b){
    return a * b / gcd(a, b);
}
