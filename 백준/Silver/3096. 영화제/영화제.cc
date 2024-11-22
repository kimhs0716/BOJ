#include <bits/stdc++.h>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifndef BOJ
    freopen("boj.in", "r", stdin);
#endif // BOJ
}

using namespace std;

using vi = vector<int>;
using lld = long long int;

int main() {
    FASTIO;
    _init();

    int n, m; cin >> n >> m;
    vector<vi> arr(n + 1, vi(n + 1));

    while (m--) {
        int a, b; cin >> a >> b;
        arr[a][b] = 1;
        arr[a][0]++;
        arr[0][b]++;
    }

    lld ans = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = i + 1; j < n + 1; j++) {
            lld cnt = 0;
            for (int k = 1; k < n + 1; k++) {
                if (arr[i][k] && arr[j][k]) cnt++;
            }
            ans += cnt * (cnt - 1) / 2;
        }
    }

    cout << ans << endl;

    return 0;
}
