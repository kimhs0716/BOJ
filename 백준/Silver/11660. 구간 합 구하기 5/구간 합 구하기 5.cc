#include <iostream>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
    FASTIO;
    
	int n, m; cin >> n >> m;
	int** arr = new int* [n + 1];
	for (int i = 0; i <= n; i++) {
		arr[i] = new int[n + 1];
		arr[i][0] = 0;
		arr[0][i] = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i + 1][j + 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] += arr[i - 1][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] += arr[i][j - 1];
		}
	}

	//for (int i = 0; i <= n; i++) {
	//	for (int j = 0; j <= n; j++) {
	//		cout << arr[i][j] << ' ';
	//	}
	//	cout << endl;
	//}

	while (m--) {
		int i, j, k, l; cin >> i >> j >> k >> l;
		cout << arr[k][l] - arr[k][j - 1] - arr[i - 1][l] + arr[i - 1][j - 1] << endl;
	}

	return 0;
}