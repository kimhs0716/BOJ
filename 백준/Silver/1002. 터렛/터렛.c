#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double dis(int x1, int y1, int x2, int y2){
    return pow(pow((double)(x1 - x2), 2) + pow((double)(y1 - y2), 2), 0.5);
}
int main() {
	int t, x1, y1, r1, x2, y2, r2;
	scanf("%d", &t);
	for(int test = 0; test < t; test++){
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        if(x1 == x2 && y1 == y2){
            if(r1 == r2) { printf("-1\n"); continue; }
            else { printf("0\n"); continue; }
        }
        double d = dis(x1, y1, x2, y2);
        if(r1 + r2 < d) { printf("0\n"); continue; }
        else if(r1 + r2 == d) { printf("1\n"); continue; }
        else if(r1 + r2 > d && abs(r1 - r2) < d) { printf("2\n"); continue; }
        else if(abs(r1 - r2) == d) { printf("1\n"); continue; }
        else printf("0\n");
	}
	return 0;
}
