#include <iostream>
#include <queue>
#include <vector>
#include <set>
#define endl '\n'

using namespace std;

typedef struct Node {
	int idx;
	vector<int> children;
	set<int> parents;
	Node(int n = 0) : idx(n) {
		children = vector<int>();
		parents = set<int>();
	}
} Node;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
	int n, m; cin >> n >> m;
	vector<Node> nodes;
	nodes.push_back(Node());
	for (int i = 1; i <= n; i++) {
		nodes.push_back(Node(i));
	}
	for (int i = 0; i < m; i++) {
		int p, c; cin >> p >> c;
		nodes[p].children.push_back(c);
		nodes[c].parents.insert(p);
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++) {
		if (nodes[i].parents.size() == 0) pq.push(i);
	}
	while (!pq.empty()) {
		int t = pq.top();
		pq.pop();
		cout << t << ' ';
		for (int c : nodes[t].children) {
			nodes[c].parents.erase(t);
			if (nodes[c].parents.size() == 0) pq.push(c);
		}
	}

	return 0;
}



