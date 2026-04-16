#include <bits/stdc++.h>
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
typedef long long int lld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
constexpr long double diff = 1e-6;
int main() {
	FASTIO;
	cout.precision(6);
	cout << fixed;
	long double h1, h2, h3; cin >> h1 >> h2 >> h3;
	long double M = 100000;
	long double m = 0;
	while (true) {
		long double s = (M + m) / 2;
		long double a = 2 * s / h1, b = 2 * s / h2, c = 2 * s / h3;
		long double t = (a + b + c) / 2;
		long double cur_s = sqrt(t * (t - a) * (t - b) * (t - c));
		if (abs(s - cur_s) < diff) {
			cout << s << endl;
			break;
		}
		//dout << cur_s << ' ' << s << endl;
		if (cur_s < s) {
			m = s;
		}
		else {
			M = s;
		}
	}

	return 0;
}