#include <iostream>
using namespace std;
int main(){
	int n;
	int wine[10010] = {};
	int dp[10010] = {};
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> wine[i];
	for (int i = 1; i < 3 && i <= n; i++) {
		if (i == 1)
			dp[i] = wine[i];
		else
			dp[i] = wine[i] + wine[i - 1];
	}
	for (int i = 3; i <= n; i++) {
		int result = 0;
		dp[i]= max(dp[i - 3] + wine[i] + wine[i - 1], dp[i - 2] + wine[i]);
		dp[i]= max(dp[i - 1], dp[i]);
	}
	cout << dp[n];
	return 0;
}
