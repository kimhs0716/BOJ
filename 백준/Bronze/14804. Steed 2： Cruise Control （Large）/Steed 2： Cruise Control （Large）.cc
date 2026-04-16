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
#include <iomanip>

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

    int tc; cin >> tc;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= tc; i++) {
        int d, n; cin >> d >> n;
        double time = 0;
        for (int i = 0; i < n; i++) {
            double k, s; cin >> k >> s;
            time = max<double>(time, (d - k) / s);
        }
        cout << "Case #" << i << ": " <<  d / time << endl;
    }

    return 0;
}
