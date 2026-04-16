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

    int a, b, c, d, e, f;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    for (int x = -999; x < 1000; x++) {
        for (int y = -999; y < 1000; y++) {
            if (a * x + b * y == c && d * x + e * y == f)
                cout << x << ' ' << y << endl;
        }
    }

    return 0;
}
