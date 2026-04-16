#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define hash_size 1024
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
typedef struct {
	int x, y;
} Pos;
typedef struct {
	Pos center;
	int radius;
} Circle;
double distance(Pos& p1, Pos& p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
istream& operator>>(istream& is, Pos& p) {
	return is >> p.x >> p.y;
}
istream& operator>>(istream& is, Circle &c) {
	return is >> c.center >> c.radius;
}
void dfs(int node, vector<vector<bool>>& adj, vector<bool>& visited) {
	for (int i = 0; i < adj.size(); i++) {
		if (adj[node][i] == 1 && visited[i] == 0) {
			visited[i] = 1;
			dfs(i, adj, visited);
		}
	}
}
int main() {
	//FASTIO;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<Circle> arr(n);
		vector<vector<bool>> adj(n);
		vector<bool> visited(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			adj[i] = vector<bool>(n);
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (distance(arr[i].center, arr[j].center) <= arr[i].radius + arr[j].radius) {
					adj[i][j] = adj[j][i] = 1;
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (visited[i] == 0) {
				cnt++;
				dfs(i, adj, visited);
			}
		}
		cout << cnt << endl;
	}

	return 0;
}