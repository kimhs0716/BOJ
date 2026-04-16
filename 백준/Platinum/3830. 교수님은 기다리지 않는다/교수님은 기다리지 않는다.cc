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

constexpr ll MOD = 1'000'000'007;
constexpr ll INF = 2147483647;

struct weighted_uf {
    ll n;
    vl grp, sz, dist;
    weighted_uf (ll n) : n(n), grp(n+1), sz(n+1, 1), dist(n+1, 0) {
        iota(grp.begin(), grp.end(), 0);
    }
    pll find(ll x) {
        if (x == grp[x]) return {x, 0};
        auto [root, diff] = find(grp[x]);
        grp[x] = root;
        dist[x] += diff;
        return {root, dist[x]};
    }
    void join(ll x, ll y, ll w) {
        auto [px, dx] = find(x);
        auto [py, dy] = find(y);
        if (py == px) return;
        grp[px] = py;
        dist[px] = dy - dx - w;
    }
};

int main() {
    FASTIO;
    _init();

    while (true) {
        ll n, m; cin >> n >> m;
        if (n == 0) break;
        
        weighted_uf uf(n);
        while (m--) {
            char q; cin >> q;
            if (q == '!') {
                ll a, b, w; cin >> a >> b >> w;
                uf.join(a, b, w);
            }
            else {
                ll a, b; cin >> a >> b;
                auto [ra, wa] = uf.find(a);
                auto [rb, wb] = uf.find(b);
                if (ra != rb) cout << "UNKNOWN\n";
                else {
                    cout << wb - wa << endl;
                }
            }
        }
    }

    return 0;
}
