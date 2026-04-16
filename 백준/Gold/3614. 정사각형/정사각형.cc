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
#include <cmath>

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

ll __pow(ll n, ll r) {
    ll ret = 1, cur = n;
    while (r) {
        if (r & 1) {
            ret = ret * cur;
        }
        cur = cur * cur;
        r >>= 1;
    }
    return ret;
}

ll __inv(ll n) {
    return __pow(n, MOD - 2, MOD);
}

vl get_primes(ll n) {
    vl arr(n + 1, 1), primes;
    arr[0] = arr[1] = 0;
    for (ll i = 2; i <= n; i++) {
        if (arr[i] == 0) continue;
        primes.push_back(i);
        for (ll j = i << 1; j <= n; j += i) {
            arr[j] = 0;
        }
    }
    return primes;
}

ll euler_phi(ll n) {
    if (n == 1) return 0;
    vl primes = get_primes(n);
    ll ret = 1;
    for (auto &p: primes) {
        ll cnt = 0;
        while (n % p == 0) {
            n /= p;
            cnt++;
            // cout << n << ' ' << p << endl;
        }
        if (cnt) {
            ll t = __pow(p, cnt - 1);
            ret *= (t * (p - 1));
        }
    }
    return ret;
}

int main() {
    FASTIO;
    _init();

    ll ans = 1;
    ll n; cin >> n;
    for (ll d = 1; d <= n; d++) {
        if (n % d) continue;
        ans += euler_phi(d + 1);
    }
    cout << ans / 2 << endl;

    return 0;
}
