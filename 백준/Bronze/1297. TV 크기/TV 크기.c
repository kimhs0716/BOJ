#include <stdio.h>
#include <math.h>
int main() {
    int a, b, c;
    double k;
    scanf("%d %d %d", &a, &b, &c);
    k = a / pow((double)(b * b + c * c), 0.5);
    printf("%d %d", (int)(k * b), (int)(k * c));
    return 0;
}
