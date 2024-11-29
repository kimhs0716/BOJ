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

int main() {
    FASTIO;
    _init();

    int n; cin >> n;

    vector<vi> arr(n, vi(3));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    sort(arr.begin(), arr.end());
    
    vector<vi> ans;
    int left = arr[0][0], right = arr[0][1], cost = arr[0][2];
    for (int i = 1; i < n; i++) {
        int s = arr[i][0], e = arr[i][1], c = arr[i][2];
        if (s > right) {
            vi cur(3);
            cur[0] = left, cur[1] = right, cur[2] = cost;
            ans.push_back(cur);
            left = s, right = e, cost = c;
        }
        else {
            right = max<int>(right, e);
            cost = min<int>(cost, c);
        }
    }
    vi cur(3);
    cur[0] = left, cur[1] = right, cur[2] = cost;
    ans.push_back(cur);

    cout << ans.size() << endl;
    for (auto i : ans) {
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << endl;
    }

    return 0;
}
