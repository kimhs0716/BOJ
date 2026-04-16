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

void solve(int n, int m, vi& arr, vi& visited, vi& cur) {
    int depth = cur.size();

    if (depth == m) {
        for (auto& i : cur) cout << i << ' ';
        cout << endl;
        return;
    }

    for (int i = 0; i < n; ) {
        if (visited[i]) {
            i++;
            continue;
        }
        //if (cur.size() && cur.back() > arr[i]) continue;
        cur.push_back(arr[i]);
        visited[i] = 1;
        solve(n, m, arr, visited, cur);
        visited[i] = 0;
        cur.pop_back();
        i++;
        while (i < n && arr[i - 1] == arr[i]) i++;
    }
}

int main() {
    FASTIO;
    _init();

    int n, m; cin >> n >> m;
    vi arr(n), visited(n), cur;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    solve(n, m, arr, visited, cur);

    return 0;
}
