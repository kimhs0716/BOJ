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

set<ll>& add(set<ll> &a, set<ll>&b) {
    // add b to a
    if (a.size() < b.size()) a.swap(b);
    // for (auto i: b) a.insert(i);
    a.merge(b);  

    return a;
}

ll mex(set<ll> &s, ll start=0) {
    ll i = start;
    while (s.contains(i)) i++;
    return i;
}

void dfs(ll node, vector<vl> &children, vector<set<ll>> &sets, vl &ans) {
    if (children[node].empty()) {
        ans[node] = mex(sets[node]);
        return;
    }
    ll max_mex = 0;
    for (ll nxt: children[node]) {
        dfs(nxt, children, sets, ans);
        add(sets[node], sets[nxt]);
        max_mex = max<ll>(max_mex, ans[nxt]);
    }
    ans[node] = mex(sets[node], max_mex);
}

int main() {
    FASTIO;
    _init();

    ll n; cin >> n;
    vector<vl> children(n + 1);
    ll root = -1;
    for (ll i = 1; i <= n; i++) {
        ll p; cin >> p;
        if (p == -1) {
            root = i;
            continue;
        };
        children[p].push_back(i);
    }
    vector<set<ll>> sets(n + 1);
    for (ll i = 1; i <= n; i++) {
        ll k; cin >> k;
        sets[i].insert(k);
    }
    vl ans(n + 1);
    dfs(root, children, sets, ans);
    for (ll i = 1; i <= n; i++) cout << ans[i] << endl;

    return 0;
}
