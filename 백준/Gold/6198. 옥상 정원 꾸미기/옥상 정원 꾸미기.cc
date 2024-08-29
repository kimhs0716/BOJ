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
using ll = long long;

int main() {
    FASTIO;
    _init();

    int n; cin >> n;
    vi st;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        while (!st.empty() && st.back() <= m) {
            st.pop_back();
        }
        ans += st.size();
        st.push_back(m);
        //for (int j : st) cout << j << ' ';
        //cout << endl;
        //cout << ans << endl;
    }

    cout << ans << endl;

    return 0;
}
