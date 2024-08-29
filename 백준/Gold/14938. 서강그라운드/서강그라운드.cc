#include <bits/stdc++.h>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifndef BOJ
      freopen("boj.in", "r", stdin);
#endif // BOJ
}

using namespace std;

using ll = long long;
using vi = vector<int>;

constexpr int INF = 0x3f3f3f;

class Graph {
public:
    int n;
    vi nodes;
    vector<vi> adj;
    vector<vi> dist;

    Graph(int size) {
        n = size;
        adj = vector<vi>(n, vi(n, INF));
        dist = vector<vi>(n, vi(n, INF));
        nodes = vi(n);
        for (int i = 0; i < n; i++) {
            cin >> nodes[i];
            dist[i][i] = 0;
        }
    }

    void add_edge(int u, int v, int w) {
        adj[u][v] = min<int>(adj[u][v], w);
        adj[v][u] = min<int>(adj[v][u], w);
        dist[u][v] = adj[u][v];
        dist[v][u] = adj[v][u];
    }

    void floyd_warshall() {
        for (int m = 0; m < n; m++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min<int>(dist[i][j], dist[i][m] + dist[m][j]);
                }
            }
        }
    }
};

int main() {
    FASTIO;
    _init();

    int n, m, r; cin >> n >> m >> r;
    Graph g(n);
    for (int i = 0; i < r; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        g.add_edge(u, v, w);
    }
    g.floyd_warshall();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++) {
            if (g.dist[i][j] <= m) cur += g.nodes[j];
        }
        ans = max<int>(ans, cur);
    }

    cout << ans << endl;

    return 0;
}
