#include <bits/stdc++.h>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifndef BOJ
    freopen("boj.in", "r", stdin);
    // freopen("boj.out", "w", stdout);
#endif // BOJ
}

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;

int solve(int i, vi& w, vi& d) {
    int ret = 0;
    if (i >= w.size()) return 0;
    if (d[i] <= 0) return solve(i + 1, w, d);
    for (int nxt = 0; nxt < w.size(); nxt++) {
        if (i == nxt) continue;
        if (d[nxt] <= 0) continue;
        d[i] -= w[nxt];
        d[nxt] -= w[i];
        ret = max<int>(ret, solve(i + 1, w, d) + (d[i] <= 0) + (d[nxt] <= 0));
        d[i] += w[nxt];
        d[nxt] += w[i];
    }
    return ret;
}

int main() {
    FASTIO;
    _init();

    int ans = 0;
    int n; cin >> n;
    vi w(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i] >> w[i];
    }
    cout << solve(0, w, d) << endl;

    return 0;
}
