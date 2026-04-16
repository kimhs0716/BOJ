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

constexpr ll MOD = 1e9 + 7;
constexpr ll MAX = 1'000'001;

int main() {
    FASTIO;
    _init();

    int tc; cin >> tc;
    while (tc--) {
        ll n; cin >> n;
        ll cnt = 0;
        ll t = 888'888'888'888'888'888;
        while (n >= 8) {
            // cout << n << ' ' << t << ' ' << cnt << endl;
            cnt += n / t;
            n %= t;
            t /= 10;
        }
        if (n != 0 || cnt > 8) cout << "No" << endl;
        else cout << "Yes" << endl;
    }

    return 0;
}
