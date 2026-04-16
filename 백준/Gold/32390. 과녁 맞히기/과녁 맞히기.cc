//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <utility> // pair

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifndef BOJ
    freopen("boj.in", "r", stdin);
    freopen("boj.out", "w", stdout);
#endif // BOJ
}

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long int;

constexpr ll MOD = 1e9 + 7;

ll __pow(ll n, ll r) {
    if (r == 0) return 1LL;
    ll ret = __pow(n, r >> 1);
    ret = ret * ret % MOD;
    if (r & 1) ret = ret * n % MOD;
    return ret;
}

ll __inv(ll n) {
    return __pow(n, MOD - 2);
}

int main() {
    FASTIO;
    _init();

    ll n, m; cin >> n >> m;
    vector<ll> arr(m);
    for (ll& i: arr) cin >> i;
    vector<ll> fac, inv_fac;
    fac.push_back(1);
    for (ll i = 1; i <= n; i++) {
        fac.push_back(fac[i - 1] * i % MOD);
    }
    inv_fac.push_back(__inv(fac.back()));
    for (ll i = n; i > 0; i--) {
        inv_fac.push_back(inv_fac.back() * i % MOD);
    }
    reverse(inv_fac.begin(), inv_fac.end());

    ll ans = fac[n];
    for (int i = 0; i < m; i++) {
        ans = ans * inv_fac[arr[i]] % MOD;
        ans = ans * __pow(2, arr[i] - 1) % MOD;
    }
    cout << ans << endl;

    return 0;
}
