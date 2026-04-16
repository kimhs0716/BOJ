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

ll __pow(ll a, ll b) {
    ll ret = 1, cur = a;
    while (b) {
        if (b & 1) ret = ret * cur % MOD;
        cur = cur * cur % MOD;
        b >>= 1;
    }
    return ret;
}

ll __inv(ll a) {
    return __pow(a, MOD - 2);
}

ll fraction(ll p, ll q) {
    return p * __inv(q) % MOD;
}

int main() {
    FASTIO;
    _init();

    ll tc; cin >> tc;
    while (tc--) {
        ll n, m; cin >> n >> m;
        n %= MOD;
        cout << fraction(n, 2) << ' ' << fraction(n, 4) << endl;
    }

    return 0;
}
