#include <iostream>
using namespace std;
int main() {
	int n;
	int t[16];
	int p[16];
	int dp[16] = { 0, };
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}
	int m;
	for (int i = 1; i <= n; i++) {
		m = 0;
		for (int j = 1; j <= i; j++) {
			if (j + t[j] - 1 <= i) m = max(dp[j - 1] + p[j], m);
		}
		dp[i] = m;
	}
	cout << m << endl;
	return 0;
}