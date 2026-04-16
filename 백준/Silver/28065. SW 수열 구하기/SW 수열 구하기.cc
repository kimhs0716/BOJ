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
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			cout << i / 2 + 1 << ' ';
		}
		else {
			cout << n - (i - 1) / 2 << ' ';
		}
	}

	return 0;
}
