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
using pii = pair<int, int>;

int main() {
    FASTIO;
    _init();

    int n, m; cin >> n >> m;
    int chicken_count = 0;
    vector<pii> chickens;
    vector<pii> houses;
    int ans = numeric_limits<int>::max();
    vector<vi> arr(n, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) houses.push_back({ i, j });
            if (arr[i][j] == 2) {
                chicken_count++;
                chickens.push_back({ i, j });
            }
        }
    }

    vi brute(chicken_count, 1);
    for (int i = 0; i < chicken_count - m; i++) brute[i] = 0;

    do {
        int temp = 0;
        for (pii house : houses) {
            int hr = house.first, hc = house.second;
            int cur = numeric_limits<int>::max();
            for (int i = 0; i < chicken_count; i++) { 
                if (brute[i] == 0) continue;
                pii chicken = chickens[i];
                int cr = chicken.first, cc = chicken.second;
                cur = min<int>(cur, abs(hr - cr) + abs(hc - cc));
            }
            temp += cur;
        }
        ans = min<int>(ans, temp);
    } while (next_permutation(brute.begin(), brute.end()));

    cout << ans << endl;

    return 0;
}
