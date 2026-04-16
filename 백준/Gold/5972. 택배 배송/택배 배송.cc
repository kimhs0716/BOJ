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
typedef vector<vi> vvi;
constexpr int inf = 1e9;
int main() {
	FASTIO;
	int n, m; cin >> n >> m;
	int s = 0;
	vector<vector<pii>> adj(n, vector<pii>());
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		bool flag = false;
		for (int j = 0; j < adj[a - 1].size(); j++) {
			if (adj[a - 1][j].first == b - 1) {
				flag = true;
				adj[a - 1][j].second = min<int>(adj[a - 1][j].second, w);
			}
		}
		if (!flag) {
			adj[a - 1].push_back({ b - 1, w });
		}
		flag = false;
		for (int j = 0; j < adj[b - 1].size(); j++) {
			if (adj[b - 1][j].first == a - 1) {
				flag = true;
				adj[b - 1][j].second = min<int>(adj[b - 1][j].second, w);
			}
		}
		if (!flag) {
			adj[b - 1].push_back({ a - 1, w });
		}
	}
	vi d(n, inf);
	vector<bool> visited(n);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pii cur = { 0, s };
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		pq.push({ d[i], i });
	}
	while (true) {
		if (pq.empty()) break;
		cur = pq.top();
		pq.pop();
		while (visited[cur.second] == 1) {
			if (pq.empty()) break;
			cur = pq.top();
			pq.pop();
		}
		if (pq.empty()) break;
		for (pii i : adj[cur.second]) {
			if (i.second + d[cur.second] < d[i.first]) {
				d[i.first] = i.second + d[cur.second];
				pq.push({ d[i.first], i.first });
			}
		}
		visited[cur.second] = 1;
	}
	cout << d[n - 1] << endl;

	return 0;
}
