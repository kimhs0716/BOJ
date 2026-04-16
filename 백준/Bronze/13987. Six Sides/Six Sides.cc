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

int main() {
    FASTIO;
    _init();

    ll win = 0, lose = 0;
    vl a(6), b(6);
    for (auto &i: a) cin >> i;
    for (auto &i: b) cin >> i;
    for (auto &i: a) {
        for (auto &j: b) {
            win += i > j;
            lose += i < j;
        }
    }

    cout.precision(5);
    cout << fixed << (ld)win / (win + lose) << endl;

    return 0;
}
