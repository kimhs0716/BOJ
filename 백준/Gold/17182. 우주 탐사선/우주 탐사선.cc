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
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
    }

    void add_edge(int u, int v, int w) {
        adj[u][v] = min<int>(adj[u][v], w);
        dist[u][v] = adj[u][v];
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

    int n, k; cin >> n >> k;
    Graph g(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g.adj[i][j];
            g.dist[i][j] = g.adj[i][j];
        }
    }
    g.floyd_warshall();

    vi route;
    for (int i = 0; i < n; i++) {
        if (i != k) route.push_back(i);
    }

    int ans = numeric_limits<int>::max();

    do {
        int cur = k;
        int val = 0;
        for (int nxt : route) {
            val += g.dist[cur][nxt];
            cur = nxt;
        }
        ans = min<int>(ans, val);
    } while (next_permutation(route.begin(), route.end()));

    cout << ans << endl;

    return 0;
}
