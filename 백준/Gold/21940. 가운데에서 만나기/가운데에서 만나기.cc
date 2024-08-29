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

    int n, m; cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        g.add_edge(u, v, w);
    }
    g.floyd_warshall();

    int f; cin >> f;
    vi farr(f);
    for (int i = 0; i < f; i++) {
        cin >> farr[i];
        --farr[i];
    }

    vi ans;
    int cur_min = numeric_limits<int>::max();
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < f; j++) {
            cur = max<int>(cur, g.dist[i][farr[j]] + g.dist[farr[j]][i]);
        }
        if (cur < cur_min) {
            cur_min = cur;
            ans.clear();
            ans.push_back(i + 1);
        }
        else if (cur == cur_min) {
            ans.push_back(i + 1);
        }
    }

    for (int node : ans) cout << node << endl;

    return 0;
}
