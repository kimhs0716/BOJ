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

int main() {
    FASTIO;
    _init();

    ll n, q; cin >> n >> q;
    vector<set<ll>> arr(n+1);
    vl idx(n+1);
    iota(idx.begin(), idx.end(), 0);
    for (ll i = 1; i <= n; i++) {
        auto &s = arr[i];
        ll m; cin >> m;
        while (m--) {
            ll k; cin >> k;
            s.insert(k);
        }
    }
    while (q--) {
        ll type; cin >> type;
        if (type == 1) {
            ll x, y; cin >> x >> y;
            if (arr[idx[x]].size() < arr[idx[y]].size()) {
                swap(idx[x], idx[y]);
            }
            x = idx[x], y = idx[y];
            for (auto &i: arr[y]) arr[x].insert(i);
            arr[y].clear();
        }
        else {
            ll x; cin >> x;
            cout << arr[idx[x]].size() << endl;
        }
        // for (auto &s: arr) {
        //     cout << "{" ;
        //     for (auto &i: s) cout << i << ' ';
        //     cout << "}\n";
        // }
    }

    return 0;
}
