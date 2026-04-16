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

int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };

int dfs(vector<vi>& arr, int r, int c, vector<vi>& visited) {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || arr.size() <= nr) continue;
        if (nc < 0 || arr[0].size() <= nc) continue;
        if (arr[nr][nc] == 1) continue;
        if (visited[nr][nc] == 1) continue;
        visited[nr][nc] = 1;
        ret += dfs(arr, nr, nc, visited) + 1;
    }
    return ret;
}

int main() {
    FASTIO;
    _init();

    int r, c, k; cin >> r >> c >> k;
    vector<vi> arr(r, vi(c)), visited(r, vi(c));
    vi ans;
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        for (int rr = y1; rr < y2; rr++) {
            for (int cc = x1; cc < x2; cc++) {
                arr[rr][cc] = 1;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == 0 && visited[i][j] == 0) {
                visited[i][j] = 1;
                ans.push_back(dfs(arr, i, j, visited) + 1);
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << ' ';
    cout << endl;

    return 0;
}
