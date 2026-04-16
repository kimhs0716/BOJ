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
	vector<string> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		string s1 = arr[i];
		for (int j = i + 1; j < n; j++) {
			string s2 = arr[j];
			bool flag = false;
			for (int k = 1; k <= min<int>(s1.size(), s2.size()); k++) {
				if (s1.substr(s1.size() - k, k) == s2.substr(0, k) || \
					s2.substr(s2.size() - k, k) == s1.substr(0, k)) {
					flag = true;
					break;
				}
			}
			ans += flag;
		}
	}
	cout << ans << endl;

	return 0;
}
