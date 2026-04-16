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
using tlll = tuple<ll, ll, double>;
using tllll = tuple<ll, ll, ll, ll>;

constexpr ll MOD = 1'000'000'007;
constexpr ll INF = 1LL << 31;

struct UF {
    ll n;
    vl grp, sz;
    UF(ll n) : n(n), grp(n+1), sz(n+1, 1) {
        iota(grp.begin(), grp.end(), 0);
    }
    ll _find(ll x) {
        if (x == grp[x]) return x;
        return grp[x] = _find(grp[x]);
    }
    void _union(ll x, ll y) {
        x = _find(x);
        y = _find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        grp[y] = x;
        sz[x] += sz[y];
    }
    bool _same(ll x, ll y) {
        return _find(x) == _find(y);
    }
    ll _size(ll x) {
        return sz[_find(x)];
    }
    void _print() {
        for (ll i = 1; i <= n; i++) {
            cout << grp[i] << ' ';
        }
        cout << endl;
        for (ll i = 1; i <= n; i++) {
            cout << sz[i] << ' ';
        }
        cout << endl;
    }
};

int main() {
    FASTIO;
    _init();

    ll n, m, q; cin >> n >> m >> q;
    UF uf(n);
    vector<pll> query(m);
    for (auto &i: query) {
        cin >> i.first >> i.second;
    }

    vl del(q), deleted(m);
    for (auto &i: del) {
        cin >> i;
        i--;
        deleted[i] = 1;
    }
    ll cost = 0;
    for (ll i = 0; i < m; i++) {
        if (deleted[i]) continue;
        auto &[a, b] = query[i];
        uf._union(a, b);
    }
    // uf._print();
    reverse(del.begin(), del.end());
    for (auto &i: del) {
        auto &[a, b] = query[i];
        if (!uf._same(a, b)) cost += uf._size(a) * uf._size(b);
        // cout << a << ' ' << b << endl;
        // cout << uf._size(a) << ' ' << uf._size(b) << endl;
        uf._union(a, b);
    }
    cout << cost << endl;

    return 0;
}
