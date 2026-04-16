//#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <utility> // pair, move
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <cassert>
#include <functional> // function
#include <numeric>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifdef KIMHS
    freopen("boj.in", "r", stdin);
    freopen("boj.out", "w", stdout);
#endif // KIMHS
}

using namespace std;

using ll = long long int;
using ld = long double;

using vl = vector<ll>;
using pll = pair<ll, ll>;
using tlll = tuple<ll, ll, ll>;

constexpr ll MOD = 1'000'000'007;
constexpr ll INF = 2147483647;

ll __pow(ll n, ll r, ll m) {
    ll ret = 1, cur = n;
    while (r) {
        if (r & 1) {
            ret = ret * cur % m;
        }
        cur = cur * cur % m;
        r >>= 1;
    }
    return ret;
}

ll __inv(ll n) {
    return __pow(n, MOD - 2, MOD);
}

int main() {
    FASTIO;
    _init();

    ll n, k; cin >> n >> k;
    if (n > k) n = k;
    vl fac(k+1), inv_fac(k+1);
    fac[0] = 1;
    for (ll i = 1; i <= k; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv_fac[k] = __inv(fac[k]);
    for (ll i = k - 1; i >= 0; i--) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ans += (fac[k] * inv_fac[i] % MOD)  * inv_fac[k-i] % MOD;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
