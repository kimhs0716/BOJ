#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define INF 1234567890

using namespace std;
typedef long long int lld;

void merge_sort(vector<int>& v, int p, int r);
void merge(vector<int>& v, int p, int q, int r);
int cnt = 0, k;
bool found = 0;

int main() {
	FASTIO;

	int n; cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	merge_sort(v, 0, n - 1);
	if (found == 0) cout << "-1\n";

	return 0;
}

void merge_sort(vector<int>& v, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(v, p, q);
		merge_sort(v, q + 1, r);
		merge(v, p, q, r);
	}
}
void merge(vector<int>& v, int p, int q, int r) {
	static vector<int> tmp(v.size());
	int i = p, j = q + 1, t = 0;
	while (i <= q && j <= r) {
		if (v[i] <= v[j]) {
			tmp[t++] = v[i++];
		}
		else {
			tmp[t++] = v[j++];
		}
	}
	while (i <= q) {
		tmp[t++] = v[i++];
	}
	while (j <= r) {
		tmp[t++] = v[j++];
	}
	i = p, t = 0;
	while (i <= r) {
		v[i++] = tmp[t++];
		cnt++;
		if (cnt == k) {
			cout << tmp[t - 1] << endl;
			found = 1;
			return;
		}
	}
}