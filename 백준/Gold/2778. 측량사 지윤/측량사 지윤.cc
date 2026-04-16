#include <bits/stdc++.h>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define inf 1987654321
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
int main() {
	FASTIO;
	cout.precision(4);
	cout << fixed;
	int t; cin >> t;
	while (t--) {
        int ta1, ta2, ta3;
        int tb1, tb2, tb3;
        int tc1, tc2, tc3;
        cin >> ta1 >> tb1 >> tc1;
        cin >> ta2 >> tb2 >> tc2;
        cin >> ta3 >> tb3 >> tc3;
        long double a1 = ta1, b1 = tb1, c1 = tc1;
        long double a2 = ta2, b2 = tb2, c2 = tc2;
        long double a3 = ta3, b3 = tb3, c3 = tc3;

        if (ta1 * tb2 == ta2 * tb1 || ta2 * tb3 == ta3 * tb2 || ta3 * tb1 == ta1 * tb3) {
            cout << "0.0000" << endl;
            continue;
        }

        long double x1 = (b2 * c1 - b1 * c2) / (a1 * b2 - a2 * b1);
        long double y1 = (c2 * a1 - c1 * a2) / (a1 * b2 - a2 * b1);

        long double x2 = (b3 * c2 - b2 * c3) / (a2 * b3 - a3 * b2);
        long double y2 = (c3 * a2 - c2 * a3) / (a2 * b3 - a3 * b2);

        long double x3 = (b1 * c3 - b3 * c1) / (a3 * b1 - a1 * b3);
        long double y3 = (c1 * a3 - c3 * a1) / (a3 * b1 - a1 * b3);

        long double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        long double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
        long double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

        long double s = (a + b + c) / 2;
        long double area = sqrt(s * (s - a) * (s - b) * (s - c));

        cout << area << endl;
	}

	return 0;
}