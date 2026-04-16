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

    queue<int> q;
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        q.push(i + 1);
    }

    int ans = 0;
    while (m--) {
        int cur = 0;
        int target; cin >> target;
        while (q.front() != target) {
            q.push(q.front());
            q.pop();
            cur++;
        }
        q.pop();
        //cout << cur << endl;
        ans += min<int>(cur, n - cur);
        n--;
    }
    cout << ans << endl;

    return 0;
}
