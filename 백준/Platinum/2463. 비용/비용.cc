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
#include <random>

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

constexpr ll MOD = 1'000'000'000;
constexpr ll INF = 2147483647;

struct UF {
    ll n;
    vl grp, sz;
    UF (ll n) : n(n), grp(n+1), sz(n+1, 1) {
        iota(grp.begin(), grp.end(), 0);
    }
    ll find(ll x) {
        return (x == grp[x]) ? x : (grp[x] = find(grp[x]));
    }
    void join(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        grp[y] = x;
    }
    bool same(ll x, ll y) {
        return find(x) == find(y);
    }
    ll size(ll x) {
        return sz[find(x)];
    }
};

int main() {
    FASTIO;
    _init();

    ll n, m; cin >> n >> m;
    UF uf(n);
    ll ans = 0, cur = 0;
    vector<tlll> edges;
    for (ll i = 0; i < m; i++) {
        ll a, b, w; cin >> a >> b >> w;
        edges.emplace_back(a, b, w);
        cur += w;
    }
    sort(edges.begin(), edges.end(), [](const tlll &left, const tlll &right) {
        return get<2>(left) > get<2>(right);
    });
    for (ll i = 0; i < m; i++) {
        auto &[a, b, w] = edges[i];
        if (!uf.same(a, b)) {
            ans += cur * uf.size(a) * uf.size(b);
            ans %= MOD;
        }
        cur -= w;
        uf.join(a, b);
    }
    cout << ans << endl;

    return 0;
}
