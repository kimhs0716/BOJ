#include <iostream>
#include <vector>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;
using vi = vector<int>;

int main() {
	FASTIO;

	int n, m, k; cin >> n >> m >> k;
	vector<char> arr(n); for (int i = 0; i < n; i++) cin >> arr[i];
	vector<bool> new_arr(n);
	for (int i = 0; i < n; i++) {
		if (arr[i] == 'R') {
			for (int j = max<int>(0, i - k); j < min<int>(n, i + k + 1); j++) new_arr[j] = 1;
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += new_arr[i];
	}

	cout << (cnt <= m ? "Yes" : "No") << endl;

	return 0;
}