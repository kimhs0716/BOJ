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
using ll = long long int;

int main() {
    FASTIO;
    _init();

    int n; cin >> n;
    int max_count = 0;
    ll max_val = numeric_limits<ll>::min();
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int idx = 0;

    while (true) {
        ll cur_val = arr[idx];
        int cur_cnt = 0;
        while (idx < n && arr[idx] == cur_val) idx++, cur_cnt++;
        if (max_count < cur_cnt) {
            max_count = cur_cnt;
            max_val = cur_val;
        }
        if (idx >= n) break;
    }

    cout << max_val << endl;

    return 0;
}
