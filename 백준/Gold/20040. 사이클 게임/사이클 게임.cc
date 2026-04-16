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

// union by rank
struct UF {
    ll n;
    vl grp, rank;
    UF(ll n) : n(n), grp(n), rank(n, 1) {
        iota(grp.begin(), grp.end(), 0);
    }
    ll _find(ll x) {
        return (x == grp[x]) ? x : _find(grp[x]);
    }
    void _union(ll x, ll y) {
        x = _find(x);
        y = _find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) rank[x]++;
        grp[y] = x;
    }
    bool _same(ll x, ll y) {
        return _find(x) == _find(y);
    }
};

int main() {
    FASTIO;
    _init();

    ll n, q; cin >> n >> q;
    UF uf(n);
    for (ll i = 0; i < q; i++) {
        ll a, b;
        cin >> a >> b;
        if (uf._same(a, b)) {
            cout << i + 1 << endl;
            return 0;
        }
        uf._union(a, b);
    }
    cout << "0\n";

    return 0;
}
