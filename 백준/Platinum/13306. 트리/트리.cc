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

struct UF {
    ll n;
    vl grp, sz;
    UF(ll n) : n(n), grp(n+1), sz(n+1, 1) {
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
};

int main() {
    FASTIO;
    _init();

    ll n, q; cin >> n >> q;
    vl parents(n+1);
    UF uf(n);
    for (ll i = 2; i <= n; i++) {
        cin >> parents[i];
    }
    q += n - 1;
    stack<pll> query;
    for (ll i = 0; i < q; i++) {
        ll x; cin >> x;
        if (x == 0) {
            ll b; cin >> b;
            query.emplace(b, -1);
        }
        else {
            ll a, b; cin >> a >> b;
            query.emplace(a, b);
        }
    }

    stack<ll> ans;
    while (q--) {
        auto [a, b] = query.top();
        query.pop();
        if (b == -1) {
            uf.join(a, parents[a]);
        }
        else {
            ans.emplace(uf.same(a, b));
        }
    }

    while (!ans.empty()) {
        cout << (ans.top() ? "YES" : "NO") << endl;
        ans.pop();
    }

    return 0;
}
