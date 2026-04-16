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
    vl grp;
    UF (ll n) : n(n), grp(n+1) {
        iota(grp.begin(), grp.end(), 0);
    }
    ll find(ll x) {
        return (x == grp[x]) ? x : (grp[x] = find(grp[x]));
    }
    void join(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        grp[y] = x;
    }
    bool same(ll x, ll y) {
        return find(x) == find(y);
    }
};

int main() {
    FASTIO;
    _init();

    ll g, p; cin >> g >> p;
    UF uf(g);
    for (ll i = 0; i < p; i++) {
        ll k; cin >> k;
        k = uf.find(k);
        if (k == 0) {
            cout << i << endl;
            return 0;
        }
        uf.join(k - 1, k);
    }
    cout << p << endl;

    return 0;
}
