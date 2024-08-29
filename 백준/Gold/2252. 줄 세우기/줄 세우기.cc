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

vi topological_sort(vector<vi>& adj, vi& indeg) {
    vi result;
    queue<int> q;
    for (int i = 1; i < adj.size(); i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        result.push_back(i);
        for (int nxt : adj[i]) {
            if (--indeg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    return result;
}

int main() {
    FASTIO;
    _init();

    int n, m; cin >> n >> m;
    vector<vi> adj(n + 1);
    vi indeg(n + 1);
    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    
    vi result = topological_sort(adj, indeg);

    for (auto r : result) cout << r << ' ';

    return 0;
}
