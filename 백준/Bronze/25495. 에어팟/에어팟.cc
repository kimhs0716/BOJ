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

    int prev = 0, cur = 0, ans = 0;
    int n; cin >> n;
    while (n--) {
        int k; cin >> k;
        if (k == prev) {
            cur <<= 1;
        }
        else {
            prev = k;
            cur = 2;
        }
        ans += cur;
        if (ans >= 100) {
            ans = 0;
            prev = 0;
            cur = 0;
        }
    }

    cout << ans << endl;

    return 0;
}
