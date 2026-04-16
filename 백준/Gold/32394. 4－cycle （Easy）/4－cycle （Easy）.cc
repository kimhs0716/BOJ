#include <bits/stdc++.h>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

using vi = vector<int>;
using ll = long long int;
using pii = pair<int, int>;

constexpr ll MOD = 1e9 + 7;

class Graph {
public:
    int n;
    vector<vi> edges;
    bool* visited;
    
    Graph(int n) : n(n) {
        edges = vector<vi>(n + 1, vi());
    }

    void add_edge(int u, int v) {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    ll dfs(int node, int start, int depth = 0) {
        if (depth && node == start) {
            return depth == 4;
        }
        if (depth == 4) {
            return node == start;
        }
        ll ret = 0;
        for (int nxt : edges[node]) {
            if (visited[nxt]) continue;
            visited[nxt] = 1;
            ret += dfs(nxt, start, depth + 1);
            visited[nxt] = 0;
        }
        return ret;
    }

    ll solve() {
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            visited = new bool[n + 1];
            memset(visited, 0, n + 1);
            ans += dfs(i, i);
            delete visited;
        }
        return ans;
    }
};

int main() {
    FASTIO;
        
    int n, m; cin >> n >> m;
    Graph g(n);
    while (m--) {
        int u, v; cin >> u >> v;
        g.add_edge(u, v);
    }
    cout << g.solve() / 8 % MOD << endl;
    
    return 0;
}
