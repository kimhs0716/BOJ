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
#include <cmath>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifdef KIMHS
    freopen("boj.in", "r", stdin);
    freopen("boj.out", "w", stdout);
#endif // KIMHS
}

using namespace std;

using ll = long long int;
using ld = long double;

using vl = vector<ll>;
using pll = pair<ll, ll>;
using tlll = tuple<ll, ll, ll>;

constexpr ll MOD = 1'000'000'007;
constexpr ll INF = 2147483647;

void add(vector<pll> &arr, ll n1, ll d1, ll n) {
    // cout << n1 << ' ' << d1 << endl;
    auto [n2, d2] = arr.back();
    ll nn = n1 + n2, dd = d1 + d2;
    bool flag = false;
    if (dd <= n && gcd(nn, dd) == 1) {
        add(arr, nn, dd, n);
        flag = true;
    }
    if (flag) add(arr, n1, d1, n);
    else arr.emplace_back(n1, d1);
}

int main() {
    FASTIO;
    _init();

    ll n, k; cin >> n >> k;
    --k;
    vector<pll> arr;
    arr.emplace_back(0, 1);
    for (ll i = n; i >= 2; i--) {
        add(arr, 1, i, n);
    }

    if (k < arr.size()) {
        cout << arr[k].first << ' ' << arr[k].second << endl;
    }
    else {
        k = 2 * arr.size() - k - 2;
        cout << arr[k].second - arr[k].first << ' ' << arr[k].second << endl;
    }

    // for (auto i: arr) cout << i.first << ' '; cout << endl;
    // for (auto i: arr) cout << i.second << ' '; cout << endl;

    return 0;
}
