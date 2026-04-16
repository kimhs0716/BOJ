#include <bits/stdc++.h>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef pair<int, int> pii;
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
int main() {
	int n, m = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		m = max<int>(m, t + i - n);
	}
	cout << m << endl;

	return 0;
}
