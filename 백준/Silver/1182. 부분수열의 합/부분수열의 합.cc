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

int bunhaehap(int i) {
    int ret = i;
    while (i) {
        ret += i % 10;
        i /= 10;
    }
    return ret;
}

int main() {
    FASTIO;
    _init();

    int n, s; cin >> n >> s;
    vi arr(n);
    int cnt = 0;
    for (auto& i : arr) cin >> i;

    for (int i = 1; i < (1 << n); i++) {
        int sum = 0;
        int t = i, idx = 0;;
        while (t) {
            sum += arr[idx++] * (t & 1);
            t >>= 1;
        }
        if (sum == s) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
