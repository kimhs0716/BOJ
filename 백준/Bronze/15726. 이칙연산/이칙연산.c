#include <stdio.h>
int main(){
    int a, b;
    double c;
	scanf("%d %d %lf", &a, &b, &c);
	printf("%d", (int)(a * ((b > c) ? (b / c) : (c / b))));
    return 0;
}
