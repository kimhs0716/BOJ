#include <iostream>
#include <vector>
#include <set>
#include <map>
#define endl '\n'

using namespace std;

typedef struct Node {
	int idx;
	set<int> parents;
	Node(int n = 0) : idx(n) {
		parents = set<int>();
	}
} Node;

int solve(int idx, vector<Node>& nodes, vector<int>& times, map<int, int>& cache) {
	if (cache.find(idx) != cache.end()) return cache[idx];
	cache[idx] = 0;
	for (auto p : nodes[idx].parents) {
		cache[idx] = max<int>(cache[idx], solve(p, nodes, times, cache));
	}
	cache[idx] += times[idx];
	return cache[idx];
}

int main() {
	int n; cin >> n;
	vector<Node> nodes(n + 1);
	vector<int> times(n + 1);
	map<int, int> cache;
	for (int i = 1; i <= n; i++) {
		nodes[i].idx = i;
		cin >> times[i];
		while (true) {
			int p; cin >> p;
			if (p == -1) break;
			nodes[i].parents.insert(p);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << solve(i, nodes, times, cache) << endl;
	}

	return 0;
}



