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

int main() {
    FASTIO;
    _init();

    map<char, int> m;
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        m[s[0]]++;
    }
    string ans;
    for (char i = 'a'; i <= 'z'; i++) {
        if (m[i] >= 5) ans.push_back(i);
    }
    if (ans.size()) cout << ans << endl;
    else cout << "PREDAJA\n";

    return 0;
}
