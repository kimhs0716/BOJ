#include <iostream>
#include <cmath>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

class debugstream {
public:
	ostream& os;
	debugstream(ostream& os) :os(os) {}
	template <typename T>
	ostream& operator<<(const T& obj) {
		return os << "#[DEBUG]: " << obj;
	}
};
debugstream dout(cout);

class Point {
public:
	double x, y;
	Point(double x, double y) : x(x), y(y) {}
	Point() : x(0), y(0) {}
	double distance(const Point& p) const {
		return pow(pow(x - p.x, 2) + pow(y - p.y, 2), 0.5);
	}
	Point operator*(double k) const {
		return Point(k * x, k * y);
	}
	Point operator+(const Point& p) const {
		return Point(x + p.x, y + p.y);
	}
};

istream& operator>>(istream& is, Point& p) {
	return is >> p.x >> p.y;
}

Point a, b, c, d;

Point operator*(double k, const Point& p) {
	return p * k;
}

Point internal_branch(const Point& p1, const Point& p2, double t) {
	return t * p2 + (1 - t) * p1;
}

double pred(double t) {
	Point p = internal_branch(a, b, t);
	Point q = internal_branch(c, d, t);
	return p.distance(q);
}

constexpr double diff = 1e-10;
double m = 0, M = 1;

int main() {
	cin >> a >> b >> c >> d;
	double mid1, mid2;
	while (true) {
		mid1 = (2 * m + M) / 3;
		mid2 = (m + 2 * M) / 3;
		double f0, f1, f2, f3;
		f0 = pred(m), f1 = pred(mid1), f2 = pred(mid2), f3 = pred(M);
		//cout << m << ' ' << mid1 << ' ' << mid2 << ' ' << M << endl;
		//cout << f0 << ' ' << f1 << ' ' << f2 << ' ' << f3 << endl;
		if (f0 >= f1 && f1 >= f2) m = mid1;
		else M = mid2;
		if (mid2 - mid1 < diff) break;
	}

	cout.precision(7);
	cout << fixed;
	cout << (pred(mid1) > diff ? pred(mid1) : 0) << endl;

	return 0;
}