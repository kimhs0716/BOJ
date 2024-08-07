#include <iostream>
#include <vector>
#include <queue>
#include <deque>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

int main() {
	FASTIO;

	// dp[i] = i번째 의뢰를 받아들였을 때의 최댓값의 최솟값
	int n, k; cin >> n >> k;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	deque<int> dq;
	vi arr(n), dp(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < k; i++) {
		dp[i] = arr[i];
		dq.push_back(dp[i]);
		pq.push(make_pair(dq.back(), i));
	}
	for (int i = k; i < n; i++) {
		while (pq.top().second < i - k) pq.pop();
		dp[i] = max<int>(pq.top().first, arr[i]);
		dq.push_back(dp[i]);
		pq.push(make_pair(dq.back(), i));
	}
	int ans = dp[n - k];
	for (int i = n - k + 1; i < n; i++) ans = min<int>(ans, dp[i]);
	cout << ans << endl;
	// for (auto i : dp) cout << i << ' ';

	return 0;
}