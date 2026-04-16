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

int solve(vector<vi>& edges, vi& cur, vi& visited, int cost) {
    if (cur.size() == visited.size()) {
        if (edges[cur.back()][0] == 0) return 2147483647;
        return cost + edges[cur.back()][0];
    }

    int ret = 2147483647;

    for (int i = 0; i < visited.size(); i++) {
        if (visited[i]) continue;
        if (edges[cur.back()][i] == 0) continue;
        visited[i] = 1;
        cost += edges[cur.back()][i];
        cur.push_back(i);
        ret = min<int>(ret, solve(edges, cur, visited, cost));
        cur.pop_back();
        cost -= edges[cur.back()][i];
        visited[i] = 0;
    }

    return ret;
}

int main() {
    FASTIO;
    _init();

    int n; cin >> n;
    vector<vi> edges(n, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> edges[i][j];
        }
    }

    vi cur, visited(n);
    cur.push_back(0);
    visited[0] = 1;
    cout << solve(edges, cur, visited, 0);

    return 0;
}
