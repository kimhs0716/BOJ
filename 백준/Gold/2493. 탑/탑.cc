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

int main() {
    FASTIO;
    _init();

    int n; cin >> n;
    vector<pii> arr(n);
    vi ans(n);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        arr[i] = { t, i };
    }

    reverse(arr.begin(), arr.end());

    stack<pii> st;
    for (auto& i : arr) {
        while (!st.empty() && st.top().first < i.first) {
            ans[st.top().second] = i.second + 1;
            st.pop();
        }
        st.push(i);
    }

    for (auto& i : ans) {
        cout << i << ' ';
    }

    return 0;
}
