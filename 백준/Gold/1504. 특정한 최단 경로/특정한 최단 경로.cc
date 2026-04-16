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

    int n, e; cin >> n >> e;
    Graph g(n + 1);
    while (e--) {
        int a, b, c; cin >> a >> b >> c;
        g.add_edge(a, b, c);
        g.add_edge(b, a, c);
    }

    int v1, v2; cin >> v1 >> v2;

    int ans1 = 0, ans2 = 0;

    g.dijkstra(1);
    ans1 += g.dist[v1];
    ans2 += g.dist[v2];

    g.dijkstra(v1);
    ans1 += g.dist[v2];
    ans2 += g.dist[n];

    g.dijkstra(v2);
    ans1 += g.dist[n];
    ans2 += g.dist[v1];

    int ans = min<int>(ans1, ans2);
    if (ans >= INF) cout << "-1\n";
    else cout << ans << endl;

    return 0;
}
