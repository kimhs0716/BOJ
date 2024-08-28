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

int n;
vector<vi> adj;
vi p;

void bfs() {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        //cout << q.size() << endl;
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]) {
            if (nxt == p[cur]) continue;
            p[nxt] = cur;
            q.push(nxt);
        }
    }
}

int main() {
    FASTIO;
    _init();

    cin >> n;
    adj = vector<vi>(n + 1);
    p = vi(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs();
    
    for (int i = 2; i <= n; i++) cout << p[i] << endl;

    return 0;
}
