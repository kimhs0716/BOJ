//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <utility> // pair
#include <set>
#include <queue>
#include <stack>
#include <map>

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
using vi = vector<int>;
using pii = pair<int, int>;

constexpr ll MOD = 1e9 + 7;
constexpr ll MAX = 1'000'001;

// less than or equal to
ll le(ll n, ll k) {
    ll ret = 0;
    for (ll i = 1; i <= n; i++) {
        ret += min<ll>(k / i, n);
    }
    return ret;
}

// less than
ll lt (ll n, ll k) {
    ll ret = 0;
    for (ll i = 1; i <= n; i++) {
        ret += min<ll>(k / i, n);
        ret -= (k % i == 0 && k / i <= n);
    }
    return ret;
}

int main() {
    FASTIO;
    _init();

    // i번째 행에서 k보다 작거나 같은 수의 개수는?
    // k / i
    // k보다 작은 수의 개수는?
    // k / i - (k % i == 0)

    ll n; cin >> n;
    ll idx; cin >> idx;

    ll lo = 0, hi = n * n;
    ll mid;
    while (lo + 1 < hi) {
        mid = (lo + hi) / 2;
        ll t = le(n, mid);
        if (t < idx) {
            lo = mid;
        }
        else {
            hi = mid;
        }
    }

    if (lt(n, lo) < idx && idx <= le(n, lo)) cout << lo << endl;
    else if (lt(n, hi) < idx && idx <= le(n, hi)) cout << hi << endl;

    return 0;
}
