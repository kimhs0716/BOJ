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
constexpr ll INF = 2147483648;
constexpr ll MAX = 1e5;

bool isprime[MAX + 1];
vl primes;

ll euler_phi(ll n) {
    if (n == 1) return 1;
    for (auto p: primes) {
        int cnt = 0;
        while (n % p == 0) {
            n /= p;
            cnt++;
        }
        if (cnt) {
            ll t = 1;
            for (int i = 0; i < cnt - 1; i++) {
                t *= p;
            }
            return euler_phi(n) * (t * p - t);
        }
    }
    return n - 1;
}

ll __pow(ll a, ll b, ll c) {
    ll ret = 1, cur = a;
    while (b) {
        if (b & 1) ret = ret * cur % c;
        cur = cur * cur % c;
        b >>= 1;
    }
    return ret;
}

int main() {
    FASTIO;
    _init();

    for (int i = 2; i <= MAX; i++) {
        isprime[i] = true;
    }

    for (int i = 2; i <= MAX; i++) {
        if (!isprime[i]) continue;
        for (int j = 2 * i; j <= MAX; j += i) {
            isprime[j] = false;
        }
    }

    for (int i = 2; i <= MAX; i++) {
        if (isprime[i]) {
            primes.push_back(i);
        }
    }

    ll n, m; cin >> n >> m;
    cout << euler_phi(m) << endl;

    return 0;
}
