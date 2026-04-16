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

struct Graph {
    ll n;
    vector<tlll> edges;
    UF uf;
    Graph(ll n) : n(n), uf(n) {}
    void add_edge(ll a, ll b, ll w) {
        edges.emplace_back(a, b, w);
    }
    ll input(ll q) {
        ll ret = 0;
        while (q--) {
            ll u, v, w; cin >> u >> v >> w;
            add_edge(u, v, w);
            ret += w;
        }
        return ret;
    }
    ll MST() {
        uf = UF(n + 1);
        ll ret = 0;
        sort(edges.begin(), edges.end(), [](const tlll &a, const tlll &b) {
            return get<2>(a) < get<2>(b);
        });
        for (auto &[u, v, w]: edges) {
            if (uf._same(u, v)) continue;
            // cout << u << ' ' << v << ' ' << w << endl;
            uf._union(u, v);
            ret += w;
        }
        return ret;
    }
};

struct Planet {
    ll x, y, z;
    ll idx;
};

int main() {
    FASTIO;
    _init();

    ll n; cin >> n;
    vector<Planet> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
        arr[i].idx = i;
    }
    Graph g(n);

    sort(arr.begin(), arr.end(), [](const Planet &left, const Planet &right) {
        return left.x < right.x;
    });
    for (ll i = 0; i < n - 1; i++) {
        g.add_edge(arr[i].idx, arr[i + 1].idx, arr[i + 1].x - arr[i].x);
    }

    sort(arr.begin(), arr.end(), [](const Planet &left, const Planet &right) {
        return left.y < right.y;
    });
    for (ll i = 0; i < n - 1; i++) {
        g.add_edge(arr[i].idx, arr[i + 1].idx, arr[i + 1].y - arr[i].y);
    }

    sort(arr.begin(), arr.end(), [](const Planet &left, const Planet &right) {
        return left.z < right.z;
    });
    for (ll i = 0; i < n - 1; i++) {
        g.add_edge(arr[i].idx, arr[i + 1].idx, arr[i + 1].z - arr[i].z);
    }

    cout << g.MST() << endl;

    return 0;
}
