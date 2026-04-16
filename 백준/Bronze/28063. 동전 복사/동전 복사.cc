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
	int x, y; cin >> x >> y;
	cout << (x != 1) + (y != 1) + (x != n) + (y != n) << endl;

	return 0;
}
