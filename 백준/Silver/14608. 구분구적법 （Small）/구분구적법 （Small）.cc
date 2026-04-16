#include <iostream>
#include <vector>
#include <cmath>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

constexpr double diff = 1e-4;

class Polynomial {
public:
	int degree;
	vector<double> coef;
	int a, b, n;
	double dx;

	Polynomial(int d) : degree(d) {
		coef = vector<double>(d + 1, 0);
		a = b = n = dx = 0;
	}

	double subs(double x) {
		double ret = 0;
		for (int i = 0; i <= degree; i++) {
			ret *= x;
			ret += coef[i];
		}
		return ret;
	}

	Polynomial integral() {
		Polynomial ret(degree + 1);
		for (int i = 0; i <= degree; i++) {
			ret.coef[i] = coef[i] / (degree - i + 1);
		}
		return ret;
	}

	double definite_integral() {
		auto i = integral();
		return i.subs(b) - i.subs(a);
	}

	double pred(double e) {
		double ret = 0;
		for (int i = 0; i < n; i++) {
			ret += subs(a + i * dx + e) * dx;
		}
		return ret;
	}
};
istream& operator>>(istream& is, Polynomial& p) {
	for (int i = 0; i <= p.degree; i++) {
		is >> p.coef[i];
	}
	is >> p.a >> p.b >> p.n;
	p.dx = static_cast<double>(p.b - p.a) / p.n;
	return is;
}
int main() {
	FASTIO;

	int k; cin >> k;
	Polynomial p(k);
	cin >> p;

	double m = 0, M = p.dx, mid;
	double yt = p.definite_integral();
	while (true) {
		mid = (m + M) / 2;
		double yp = p.pred(mid);
		if (abs(yp - yt) < diff) break;
		if (yp < yt) m = mid;
		else M = mid;
	}

	cout << mid << endl;

	return 0;
}
