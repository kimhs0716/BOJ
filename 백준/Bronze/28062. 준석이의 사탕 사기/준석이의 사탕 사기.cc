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
	vi arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	if (n == 1 && arr[0] % 2 == 1) {
		cout << "0\n";
	}
	else {
		int ans = 0, m = 2147483647, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] % 2 == 1) {
				m = min<int>(m, arr[i]);
				cnt++;
			}
			ans += arr[i];
		}
		if (cnt % 2 == 1) {
			ans -= m;
		}
		cout << ans << endl;
	}

	return 0;
}
