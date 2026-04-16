#include <iostream>
#include <vector>
#include <set>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

using vi = vector<int>;

vector<vi> cache(100, vi(100, -1));

int mex(set<int> s) {
	int i = -1;
	while (s.find(++i) != s.end());
	return i;
}

int g(int r, int c) {
    if (r < c) return g(c, r);
	int& ret = cache[r][c];
	if (ret != -1) return ret;
	set<int> s;
	for (int i = 1; i < (r + 1) / 2; i++) {
		s.insert(g(i, c) ^ g(r - i - 1, c));
	}
	for (int i = 1; i < (c + 1) / 2; i++) {
		s.insert(g(r, i) ^ g(r, c - i - 1));
	}
	return ret = mex(s);
}

int main() {
	FASTIO;

	int n, m; cin >> n >> m;
	if (n >= 56) n = (n - 56) % 34 + 56;
	if (m >= 56) m = (m - 56) % 34 + 56;

	cout << (g(n, m) ? "sh" : "hs") << endl;

	return 0;
}