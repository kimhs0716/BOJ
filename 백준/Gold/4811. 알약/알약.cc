#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int lld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
constexpr int mod = 1e9 + 7;
lld arr[31][31];
int main() {
	arr[1][0] = arr[1][30] = 1;
	for (int i = 2; i <= 30; i++) {
		arr[i][0] = 1;
		lld s = arr[i][0];
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
			s += arr[i][j];
		}
		arr[i][30] = s;
	}
	while (true) {
		int n; cin >> n;
		if (!n) break;
		cout << arr[n][30] << endl;
	}

	return 0;
}