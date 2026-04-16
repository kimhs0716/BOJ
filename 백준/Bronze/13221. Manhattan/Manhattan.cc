#include <iostream>
#include <string>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define pii pair<int, int>
using namespace std;
int main() {
    FASTIO;
    pii c, t, ans;
    int min = 1 << 8, n;
    cin >> c.first >> c.second;
    cin >> n;
    while (n--) {
        cin >> t.first >> t.second;
        int cur = abs(t.first - c.first) + abs(t.second - c.second);
        if (cur < min) {
            min = cur;
            ans = t;
        }
    }
    cout << ans.first << ' ' << ans.second << endl;
    return 0;
}
