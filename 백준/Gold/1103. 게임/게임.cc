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

constexpr ll INF = 214748;

int rr, cc;
vector<vi> dp;

int dfs(int r, int c, vector<vi>& arr, int cnt, set<pii>& visited) {
    int nr, nc;
    int ret = 0;

    if (arr[r][c] == 0) return cnt;
    if (dp[r][c] != 0) return cnt + dp[r][c];

    // left
    nr = r, nc = c - arr[r][c];
    if (nc < 0) ret = max<int>(ret, cnt);
    else if (visited.count({ nr, nc })) {
        return INF;
    }
    else {
        visited.insert({ nr, nc });
        ret = max<int>(ret, dfs(nr, nc, arr, cnt, visited));
        visited.erase({ nr, nc });
    }

    // right
    nr = r, nc = c + arr[r][c];
    if (nc >= cc) ret = max<int>(ret, cnt);
    else if (visited.count({ nr, nc })) {
        return INF;
    }
    else {
        visited.insert({ nr, nc });
        ret = max<int>(ret, dfs(nr, nc, arr, cnt, visited));
        visited.erase({ nr, nc });
    }

    // up
    nr = r - arr[r][c], nc = c;
    if (nr < 0) ret = max<int>(ret, cnt);
    else if (visited.count({ nr, nc })) {
        return INF;
    }
    else {
        visited.insert({ nr, nc });
        ret = max<int>(ret, dfs(nr, nc, arr, cnt, visited));
        visited.erase({ nr, nc });
    }

    // down
    nr = r + arr[r][c], nc = c;
    if (nr >= rr) ret = max<int>(ret, cnt);
    else if (visited.count({ nr, nc })) {
        return INF;
    }
    else {
        visited.insert({ nr, nc });
        ret = max<int>(ret, dfs(nr, nc, arr, cnt, visited));
        visited.erase({ nr, nc });
    }

    return dp[r][c] = ret + 1;
}

int main() {
    FASTIO;
    _init();

    cin >> rr >> cc;
    vector<vi> arr(rr, vi(cc));
    dp = vector<vi>(rr, vi(cc));
    set<pii> visited;
    visited.insert({ 0, 0 });
    for (int i = 0; i < rr; i++) {
        for (int j = 0; j < cc; j++) {
            char ch; cin >> ch;
            if (ch == 'H') arr[i][j] = 0;
            else arr[i][j] = ch - '0';
        }
    }
    int ans = dfs(0, 0, arr, 0, visited);
    if (ans >= INF) cout << "-1\n";
    else cout << ans << endl;

    return 0;
}
