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
using pii = pair<int, int>;

constexpr int INF = 0x3f3f3f;

class Graph {
public:
    int n;
    vector<pii> max_l;
    vector<vi> min_adj, max_adj;
    vector<vi> dist;

    Graph(int size) {
        n = size;
        min_adj = vector<vi>(n, vi(n, INF));
        max_adj = vector<vi>(n, vi(n));
        dist = vector<vi>(n, vi(n, INF));
        max_l = vector<pii>(n);
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
            min_adj[i][i] = max_adj[i][i] = 0;
        }
    }

    void add_edge(int u, int v, int w) {
        min_adj[u][v] = min<int>(min_adj[u][v], w);
        min_adj[v][u] = min<int>(min_adj[v][u], w);
        max_adj[u][v] = max<int>(max_adj[u][v], w);
        max_adj[v][u] = max<int>(max_adj[v][u], w);
        dist[u][v] = min_adj[u][v];
        dist[v][u] = min_adj[v][u];
        if (max_l[u].first < w) max_l[u] = { w, v };
        if (max_l[v].first < w) max_l[v] = { w, u };
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

    int n, m; cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        g.add_edge(u, v, w);
    }
    g.floyd_warshall();

    int ans = numeric_limits<int>::max();
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                int max_time_double;
                int t1 = g.dist[i][u];
                int t2 = g.dist[i][v];
                if (g.min_adj[u][v] == INF) max_time_double = 2 * max<int>(t1, t2);
                else {
                    max_time_double = max<int>(t1, t2) * 2 + g.max_adj[u][v] - abs<int>(t1 - t2);
                    if (max_time_double < 0) max_time_double = 0;
                }
                cur = max<int>(cur, max_time_double);
            }
        }
        ans = min<int>(ans, cur);
    }

    cout.precision(1);
    cout << fixed;
    cout << ans / 2.0 << endl;

    return 0;
}
