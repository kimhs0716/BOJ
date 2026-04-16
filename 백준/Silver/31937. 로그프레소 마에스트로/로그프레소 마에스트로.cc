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
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr ll MOD = 1000;
constexpr ll INF = 1'000'000'001;

typedef struct {
    int time, a, b;
} log;

int pred(int start, vector<log> &arr, vi &infected, int n) {
    vi virus(n + 1, 0);
    if (infected[start] == 0) return -1;
    virus[start] = 1;
    int ret = 1;
    for (log l: arr) {
        if (virus[l.a] == 1 && virus[l.b] == 0) {
            ret++;
            virus[l.b] = 1;
            if (infected[l.b] == 0) return -1;
        }
    }
    return ret;
}

bool operator<(const log &a, const log &b) {
    return a.time < b.time;
}

int main() {
    FASTIO;
    _init();

    vector<log> arr;
    int n, m, k; cin >> n >> m >> k;
    vi infected(n + 1, 0);
    for (int i = 0; i < k; i++) {
        int t; cin >> t;
        infected[t] = 1;
    }
    for (int i = 0; i < m; i++) {
        int t, a, b; cin >> t >> a >> b;
        arr.emplace_back(t, a, b);
    }
    sort(arr.begin(), arr.end());

    for (int i = 1; i <= n; i++) {
        if (pred(i, arr, infected, n) == k) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
