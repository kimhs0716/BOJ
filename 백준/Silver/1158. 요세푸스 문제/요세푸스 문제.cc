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
    int n, k; cin >> n >> k;
    vi ans;
    for (int i = 1; i <= n; i++) q.push(i);
    while (!q.empty()) {
        for (int i = 0; i < k - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        ans.push_back(q.front());
        q.pop();
    }

    cout << '<';
    for (int i = 0; i < n - 1; i++)
        cout << ans[i] << ", ";
    cout << ans.back() << '>' << endl;

    return 0;
}
