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
constexpr ll INF = 2147483647;

int main() {
    FASTIO;
    _init();

    ll n, q; cin >> n >> q;
    vl arr(n);
    for (auto &i: arr) cin >> i;
    while (q--) {
        ll type, a, b;
        cin >> type >> a >> b;
        --a, --b;
        if (type == 1) {
            ll s = 0;
            for (ll i = a; i <= b; i++) s += arr[i];
            cout << s << endl;
            swap(arr[a], arr[b]);
        }
        else {
            ll c, d; cin >> c >> d;
            --c, --d;
            ll s1 = 0, s2 = 0;
            for (ll i = a; i <= b; i++) s1 += arr[i];
            for (ll i = c; i <= d; i++) s2 += arr[i];
            cout << s1 - s2 << endl;
        }
    }

    return 0;
}
