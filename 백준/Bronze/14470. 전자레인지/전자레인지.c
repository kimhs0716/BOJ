#include <stdio.h>
int main(){
    int a, b, c, d, e, f = 0;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	if(a < 0) f += -a * c + d;
	f += (b - ((a < 0) ? 0 : a)) * e;
	printf("%d", f);
    return 0;
}
