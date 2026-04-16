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
#ifndef BOJ
    freopen("boj.in", "r", stdin);
    freopen("boj.out", "w", stdout);
#endif // BOJ
}

using namespace std;

using ll = long long int;
using vl = vector<ll>;
using pll = pair<ll, ll>;
using tlll = tuple<ll, ll, ll>;

constexpr ll MOD = 1'000'000'007;
constexpr ll INF = 1LL << 31;

struct UF {
    ll n;
    vl grp;
    UF(ll n) : n(n), grp(n+1) {
        iota(grp.begin(), grp.end(), 0);
    }
    ll _find(ll x) {
        if (x == grp[x]) return x;
        return grp[x] = _find(grp[x]);
    }
    void _union(ll x, ll y) {
        x = _find(x);
        y = _find(y);
        grp[x] = y;
    }
    bool _same(ll x, ll y) {
        return _find(x) == _find(y);
    }
};

int main() {
    FASTIO;
    _init();

    ll ans = 0;
    ll n, q; cin >> n >> q;
    ll can_place = 0;
    UF uf(n);
    for (ll i = 0; i < q; i++) {
        can_place++;
        ll a, b; cin >> a >> b;
        if (uf._same(a, b)) continue;
        for (ll j = uf._find(a); j < b; j = uf.grp[j]) {
            if (can_place == 0) ans++;
            else can_place--;
            uf._union(j, j + 1);
        }
        uf._find(a);
        // for (auto &i: uf.grp) cout << i << ' ';
        // cout << endl;
    }
    cout << ans << endl;

    return 0;
}
