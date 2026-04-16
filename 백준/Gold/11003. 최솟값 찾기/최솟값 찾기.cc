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
using ll = long long int;
using pll = pair<ll, ll>;

int main() {
    FASTIO;
    _init();

    int n, l; cin >> n >> l;
    deque<pii> dq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        while (!dq.empty() && dq.back().first >= x) dq.pop_back();
        dq.push_back({ x, i });
        if (dq.front().second < i - l + 1) dq.pop_front();
        cout << dq.front().first << ' ';
    }

    return 0;
}
