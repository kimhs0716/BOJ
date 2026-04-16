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

    int n, k; cin >> n >> k;
    string s; cin >> s;
    string ans;

    for (auto& ch : s) {
        while (k && ans.size() && ans.back() < ch) {
            ans.pop_back();
            k--;
        }
        ans.push_back(ch);
    }

    while (k--) ans.pop_back();

    cout << ans << endl;

    return 0;
}
