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

ll __pow(ll a, ll b, ll m) {
    ll ret = 1, cur = a;
    while (b) {
        if (b & 1) ret = ret * cur % m;
        cur = cur * cur % m;
        b >>= 1;
    }
    return ret;
}

ll __inv(ll a) {
    return __pow(a, MOD - 2, MOD);
}

int main() {
    FASTIO;
    _init();

    vl fac(2000001);
    fac[0] = 1;
    for (ll i = 1; i <= 2000000; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    ll tc; cin >> tc;
    while (tc--) {
        ll n; cin >> n;
        cout << (fac[n << 1] * __inv(fac[n + 1]) % MOD) * __inv(fac[n]) % MOD << endl;
    }

    return 0;
}
