#include <stdio.h>
int main(){
    int a, b;
    long long int c;
	scanf("%d %d %lld", &a, &b, &c);
	printf("%lld", ((a + c - 1) / c) * ((b + c - 1) / c));
    return 0;
}
