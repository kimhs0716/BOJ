#include <bits/stdc++.h>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
	FASTIO;
	int n; cin >> n;
	ll ans = 0; int e = -2147483648;
	vector<pii> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());
	for (auto i : arr) {
		//cout << i.first << ' ' << i.second << endl;
		if (i.second <= e) continue;
		if (i.first <= e) {
			ans += (i.second - e);
			e = i.second;
		}
		else {
			ans += (i.second - i.first);
			e = i.second;
		}
	}
	cout << ans << endl;

	return 0;
}