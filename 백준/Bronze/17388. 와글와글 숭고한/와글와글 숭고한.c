#include <stdio.h>
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a + b + c >= 100) printf("OK");
    else{
        (a < b && a < c) && printf("Soongsil");
        (b < a && b < c) && printf("Korea");
        (c < a && c < b) && printf("Hanyang");
    }
    return 0;
}
