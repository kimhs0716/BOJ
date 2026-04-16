//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <utility> // pair
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <cassert>

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
using pii = pair<int, int>;

constexpr ll MOD = 1000;
constexpr ll MAX = 1'000'001;

int main() {
    FASTIO;
    _init();

    int a, b, c; cin >> a >> b >> c;
    if (a + b == c) cout << "correct!\n";
    else cout << "wrong!\n";

    return 0;
}
