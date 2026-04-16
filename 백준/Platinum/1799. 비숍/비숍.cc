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

vector<bitset<10>> arr(10);

int solve(int n, int idx, int left, int right, int cnt, int color) {
    if (idx >= n * n) {
        return cnt;
    }
    int r = idx / n, c = idx % n;
    while (r < n && arr[r][c] == 0) {
        idx += 1;
        r = idx / n, c = idx % n;
    }
    if ((r + c) % 2 != color) return solve(n, idx + 1, left, right, cnt, color);
    if (r == n) return solve(n, idx, left, right, cnt, color);
    int ret = solve(n, idx + 1, left, right, cnt, color);
    int left_bit = 1 << (r + c);
    int right_bit = 1 << (r - c + n - 1);
    if ((left & left_bit) != 0 || (right & right_bit) != 0) return ret;
    ret = max<int>(ret, solve(n, idx + 1, left | left_bit, right | right_bit, cnt + 1, color));
    return ret;
}

int main() {
    FASTIO;
    _init();

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t; cin >> t;
            arr[i][j] = (t == 1);
        }
    }

    int ans1 = solve(n, 0, 0, 0, 0, 0);
    int ans2 = solve(n, 1, 0, 0, 0, 1);
    cout << ans1 + ans2 << endl;

    return 0;
}
