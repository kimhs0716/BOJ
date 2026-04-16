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

using ll = long long int;
using vl = vector<ll>;
using pll = pair<ll, ll>;

constexpr ll MOD = 1e9 + 7;
constexpr ll MAX = 4'000'001;

ll __pow(ll n, ll r) {
    if (r == 0) return 1LL;
    ll ret = 1LL;
    ll cur = n;
    while (r) {
        if (r & 1) {
            ret = ret * cur % MOD;
        }
        cur = cur * cur % MOD;
        r >>= 1;
    }
    return ret;
}

ll __inv(ll n) {
    return __pow(n, MOD - 2);
}

int main() {
    FASTIO;
    _init();

    ll n, k; cin >> n >> k;
    vl fac, inv_fac;
    fac.push_back(1);
    for (ll i = 1; i <= n; i++) {
        fac.push_back(i * fac.back() % MOD);
    }

    cout << (fac[n] * __inv(fac[k]) % MOD) * __inv(fac[n - k]) % MOD << endl;


    return 0;
}
