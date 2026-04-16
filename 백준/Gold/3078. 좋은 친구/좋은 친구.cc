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

    int n, k; cin >> n >> k;
    ll ans = 0;
    vi arr;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        arr.push_back(s.length());
    }
    map<int, int> m;
    int left = 0, right = 0;
    for (; right <= k; right++) {
        ans += m[arr[right]]++;
    }
    for (; right < n; right++) {
        m[arr[left++]]--;
        ans += m[arr[right]]++;
    }
    cout << ans << endl;

    return 0;
}
