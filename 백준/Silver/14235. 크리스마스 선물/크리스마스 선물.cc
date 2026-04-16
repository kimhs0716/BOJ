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

	priority_queue<int> pq;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n == 0) {
			if (pq.empty()) cout << -1 << endl;
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else {
			while (n--) {
				int k; cin >> k;
				pq.push(k);
			}
		}
	}

	return 0;
}