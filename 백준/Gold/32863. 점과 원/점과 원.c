#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define DIFF 1e-6

typedef struct {
	double x, y;
} Point;

double slope(Point p1, Point p2) {
	return (double)(p2.y - p1.y) / (p2.x - p1.x);
}

double distance(Point p1, Point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

Point mid(Point p1, Point p2) {
	Point p;
	p.x = (p1.x + p2.x) / 2;
	p.y = (p1.y + p2.y) / 2;
	return p;
}

int main() {
	Point p1, p2, p3, p4;
	scanf("%lf %lf", &p1.x, &p1.y);
	scanf("%lf %lf", &p2.x, &p2.y);
	scanf("%lf %lf", &p3.x, &p3.y);
	scanf("%lf %lf", &p4.x, &p4.y);

	if (slope(p1, p2) == slope(p1, p3)) {
		Point tmp = p3;
		p3 = p4;
		p4 = tmp;
	}

	Point o, m1, m2;
	m1 = mid(p1, p2);
	m2 = mid(p1, p3);

	if (fabs(p1.y - p2.y) < DIFF) {
		o.x = m1.x;
		o.y = -1 / slope(p1, p3) * (m1.x - m2.x) + m2.y;
	}
	else if (fabs(p1.y - p3.y) < DIFF) {
		o.x = m2.x;
		o.y = -1 / slope(p1, p2) * (m2.x - m1.x) + m1.y;
	}
	else {
		double s1 = slope(p1, p2);
		double s2 = slope(p1, p3);
		s1 = -1 / s1;
		s2 = -1 / s2;
		o.x = (s1 * m1.x - s2 * m2.x + m2.y - m1.y) / (s1 - s2);
		o.y = s1 * (o.x - m1.x) + m1.y;
	}

	printf("%.4lf %.4lf ", o.x, o.y);

	double min_r = 0, max_r = 500000;
	double mid_r = 0;

	while (max_r - min_r > DIFF) {
		mid_r = (min_r + max_r) / 2;
		//printf("%.4lf, %.4lf, %.4lf\n", min_r, mid_r, max_r);
		double d1 = mid_r - distance(o, p1);
		double d2 = distance(o, p4) - mid_r;
		if (d1 < d2) {
			min_r = mid_r;
		}
		else {
			max_r = mid_r;
		}
	} 

	printf("%.4lf", mid_r);

	return 0;
}
