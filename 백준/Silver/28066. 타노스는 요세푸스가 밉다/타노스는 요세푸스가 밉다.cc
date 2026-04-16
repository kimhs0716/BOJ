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
	int n, k; cin >> n >> k;
	deque<int> dq;
	for (int i = 1; i <= n; i++) dq.push_back(i);
	while (dq.size() >= k) {
		dq.push_back(dq.front());
		for (int i = 0; i < k; i++) dq.pop_front();
	}
	cout << dq.front() << endl;

	return 0;
}
