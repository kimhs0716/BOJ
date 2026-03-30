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

ll __pow(ll a, ll b, ll c) {
    ll ret = 1, cur = a;
    while (b) {
        if (b & 1) {
            ret *= cur;
            ret %= c;
        }
        b >>= 1;
        cur = cur * cur % c;
    }
    return ret;
}

int main() {
    FASTIO;
    _init();

    ll a, b, c; cin >> a >> b >> c;
    cout << __pow(a, b, c) << endl;

    return 0;
}
