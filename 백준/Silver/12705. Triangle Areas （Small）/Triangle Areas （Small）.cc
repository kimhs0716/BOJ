#include <iostream>
#include <cmath>
#include <cstdio>

#define endl '\n'

using namespace std;

int cross(int x1, int y1, int x2, int y2) {
    return abs(x1 * y2 - x2 * y1);
}

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        int n, m, a;
        cin >> n >> m >> a;
        if (n * m < a) {
            cout << "Case #" << tc + 1 << ": IMPOSSIBLE" << endl;
            continue;
        }
        bool flag = false;
        for (int x1 = 0; x1 <= n; ++x1) {
            for (int y1 = 0; y1 <= m; ++y1) {
                for (int x2 = 0; x2 <= n; ++x2) {
                    for (int y2 = 0; y2 <= m; ++y2) {
                        if (cross(x1, y1, x2, y2) == a) {
                            cout << "Case #" << tc + 1 << ": 0 0 " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
                            flag = true;
                            break;
                        }
                    }
                    if (flag) break;
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (!flag) cout << "Case #" << tc + 1 << ": IMPOSSIBLE" << endl;
    }
    return 0;
}
