#include <iostream>
#include <vector>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll = long long int;
using vll = vector<ll>;

ll _max(vll& arr, int left, int right) {
	ll ans = 0;
	for (int i = left; i < right; i++) {
		ans = max<ll>(ans, arr[i]);
	}
	return ans;
}

int main() {
    FASTIO;

	int n; cin >> n;
	vll weight(n), energy(n);
	vll dp;
	
	for (int i = 0; i < n; i++) cin >> weight[i];
	for (int i = 0; i < n; i++) cin >> energy[i];

	dp.push_back(0);
	dp.push_back(weight[0] * energy[0]);

	for (int i = 1; i < n; i++) {
		ll w = weight[i], e = energy[i];
		ll t = w * e + dp[i];
		for (int j = 0; j < i; j++) {
			ll Mw = _max(weight, j, i + 1);
			ll Me = _max(energy, j, i + 1);
			t = min<ll>(t, Mw * Me + dp[j]);
		}
		dp.push_back(t);
	}

	cout << dp.back() << endl;

	return 0;
}