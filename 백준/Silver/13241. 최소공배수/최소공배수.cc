#include <bits/stdc++.h>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifndef BOJ
	freopen("boj.in", "r", stdin);
	// freopen("boj.out", "w", stdout);
#endif // BOJ
}

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long int;

ll gcd(ll a, ll b) {
	if (a < b) return gcd(b, a);
	while (b) {
		ll t = a % b;
		a = b;
		b = t;
	}
	return a;
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	FASTIO;
	_init();

	ll n, m; cin >> n >> m;
	cout << lcm(n, m) << endl;

	return 0;
}
