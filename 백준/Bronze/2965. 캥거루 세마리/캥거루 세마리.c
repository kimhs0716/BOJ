#include <stdio.h>
int main() {
	int a, b, c, s;
	scanf("%d %d %d", &a, &b, &c);
	s = c - b > b - a ? c - b : b - a;
	printf("%d", s - 1);
}
