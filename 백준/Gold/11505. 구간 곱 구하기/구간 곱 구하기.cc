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
using vi = vector<ll>;
using pii = pair<ll, ll>;

constexpr ll MOD = 1'000'000'007;
constexpr ll INF = 2147483647;

struct SegTree {
    vi tree;
    vi &arr;
    ll n, identity;
    function<ll(ll, ll)> func;

    SegTree(ll n, vi &arr, function<ll(ll, ll)> f, ll identity) : n(n), arr(arr), func(f) {
        tree.resize(n << 2);
        init(0, n, 1);
        this->identity = identity;
    }

    ll init(ll start, ll end, ll index) {
        if (start + 1 >= end) {
            return tree[index] = arr[start];
        }
        ll mid = (start + end) >> 1;
        return tree[index] = \
               func(init(start, mid, index << 1), init(mid, end, (index << 1) + 1));
    }

    ll get_sum(ll start, ll end, ll index, ll left, ll right) {
        if (right < start || end <= left) return identity;
        if (left <= start && end <= right + 1) return tree[index];
        ll mid = (start + end) >> 1;
        return func(get_sum(start, mid, index << 1, left, right), \
                    get_sum(mid, end, (index << 1) + 1, left, right));
    }

    ll update(ll l, ll r, ll idx, ll pos, ll val) {
        if (pos < l || r <= pos)          // [l,r) 밖
            return tree[idx];             // 그대로 반환

        if (l + 1 == r)                   // 잎 노드
            return tree[idx] = val;

        ll m = (l + r) >> 1;
        tree[idx] = func(update(l, m, idx<<1,     pos, val),
                         update(m, r, idx<<1|1, pos, val));
        return tree[idx];
    }

};

int main() {
    FASTIO;
    _init();

    ll n, m, k; cin >> n >> m >> k;
    vi arr(n);
    for (auto &i: arr) cin >> i;

    SegTree tree(n, arr, [](const ll a, const ll b) {
        return a * b % MOD;
    }, 1);

    m += k;
    while (m--) {
        ll a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            b--;
            tree.update(0, n, 1, b, c);
        }
        else {
            b--, c--;
            cout << tree.get_sum(0, n, 1, b, c) << endl;
        }
    }

    return 0;
}
