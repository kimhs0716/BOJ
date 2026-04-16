#include <stdio.h>
#define PI 3.14159265358979323846264338327950288419716939937510582097494459

int main() {
	int r;
	scanf("%d", &r);
	printf("%.10f\n%.10f", r * r * PI, r * r * 2.0);
	return 0;
}
