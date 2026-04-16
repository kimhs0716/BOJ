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
using ll = long long int;

int main() {
    FASTIO;
    _init();

    string s; cin >> s;
    int ans = 0;
    int cnt = 0;
    char prev = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            cnt++;
        }
        else {
            cnt--;
            if (prev == '(') {
                ans += cnt;
            }
            else {
                ans++;
            }
        }
        prev = s[i];
    }

    cout << ans << endl;

    return 0;
}
