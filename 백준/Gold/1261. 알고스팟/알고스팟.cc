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

constexpr int INF = 2e8;

class Graph {
public:
    int n;
    vector<pii> max_l;
    vector<vector<pii>> adj;
    vi dist;

    Graph(int size) {
        n = size;
        adj = vector<vector<pii>>(n);
        dist = vi(n, INF);
    }

    void add_edge(int u, int v, int w) {
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    void dijkstra(int start) {
        dist = vi(n, INF);
        dist[start] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (auto nxt : adj[start]) {
            if (dist[nxt.first] > nxt.second) {
                dist[nxt.first] = nxt.second;
                pq.push({ dist[nxt.first], nxt.first });
            }
        }
        while (!pq.empty()) {
            int u, w;
            tie(w, u) = pq.top();
            pq.pop();
            if (dist[u] != w) continue;
            for (pii nxt : adj[u]) {
                if (dist[nxt.first] > dist[u] + nxt.second) {
                    dist[nxt.first] = dist[u] + nxt.second;
                    pq.push({ dist[nxt.first], nxt.first });
                }
            }
        }
    }

    void print() {
        for (int i = 0; i < n; i++) {
            if (dist[i] >= INF) cout << "INF" << ' ';
            else cout << dist[i] << ' ';
        }
        cout << endl;
    }
};

int main() {
    FASTIO;
    _init();

    int n, m; cin >> m >> n;
    vector<vector<bool>> arr(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = (s[j] == '1');
        }
    }
    Graph g(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j + 1 < m) {
                g.add_edge(i * m + j, i * m + j + 1, arr[i][j + 1] + arr[i][j]);
            }
            if (i + 1 < n) {
                g.add_edge(i * m + j, (i + 1) * m + j, arr[i + 1][j] + arr[i][j]);
            }
        }
    }

    g.dijkstra(0);

    cout << g.dist[n * m - 1] / 2 << endl;

    return 0;
}
