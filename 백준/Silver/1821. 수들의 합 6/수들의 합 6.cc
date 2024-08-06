#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;
using vi = vector<int>;

int dot(vi& u, vi& v) {
	int sum = 0;
	for (int i = 0; i < u.size(); i++)
		sum += u[i] * v[i];
	return sum;
}

int main() {
	FASTIO;

	int n, f; cin >> n >> f;
	vector<vi> comb(n, vi(n));
	for (int i = 0; i < n; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++)
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
	}
	vi cur(n);
	for (int i = 0; i < n; i++) cur[i] = i + 1;

	while (true) {
		if (dot(cur, comb[n - 1]) == f) {
			for (auto i : cur) cout << i << ' ';
			cout << endl;
			break;
		}
		next_permutation(cur.begin(), cur.end());
	}

	return 0;
}
