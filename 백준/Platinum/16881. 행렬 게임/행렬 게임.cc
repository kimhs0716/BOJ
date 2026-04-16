#include <iostream>
#include <vector>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

using vi = vector<int>;

int g(vi& arr, int idx = 0) {
	if (idx + 1 == arr.size()) return arr[idx];
	int t = g(arr, idx + 1);
	if (arr[idx] == 0) return t;
	if (arr[idx] <= t) return arr[idx] - 1;
	return arr[idx];
}

int main() {
	FASTIO;

	int n, m; cin >> n >> m;
	int x = 0;
	while (n--) {
		vi arr(m);
		for (int i = 0; i < m; i++) cin >> arr[i];
		x ^= g(arr);
	}

	cout << (x ? "koosaga" : "cubelover") << endl;

	return 0;
}