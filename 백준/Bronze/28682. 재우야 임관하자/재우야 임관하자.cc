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

    ll n; cin >> n;
    string bo = "bowling", sw = "swimming", so = "soccer";
    for (ll i = 0; i < n; i++) cout << bo << ' ';
    cout << endl << flush;
    for (ll i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == sw) cout << so << ' ';
        else cout << sw << ' ';
    }
    cout << endl << flush;

    return 0;
}
