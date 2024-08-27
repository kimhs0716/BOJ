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

int _count[2000005];

int main() {
    FASTIO;
    _init();

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        _count[m + 1000000]++;
    }

    for (int i = 0; i < 2000005; i++) {
        while (_count[i]--) cout << i - 1000000 << endl;
    }

    return 0;
}
