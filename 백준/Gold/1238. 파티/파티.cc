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

constexpr int INF = 1e6;

class Graph {
public:
    int n;
    vector<pii> max_l;
    vector<vector<pii>> adj;
    vi dist, prev;

    Graph(int size) {
        n = size;
        adj = vector<vector<pii>>(n);
        dist = vi(n, INF);
        prev = vi(n, -1);
    }

    void add_edge(int u, int v, int w) {
        adj[u].push_back({ v, w });
    }

    void dijkstra(int start) {
        dist[start] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (auto nxt : adj[start]) {
            if (dist[nxt.first] > nxt.second) {
                dist[nxt.first] = nxt.second;
                pq.push({ dist[nxt.first], nxt.first });
                prev[nxt.first] = start;
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
                    prev[nxt.first] = u;
                }
            }
        }
    }
};

int main() {
    FASTIO;
    _init();

    int v, e, x; cin >> v >> e >> x;
    x--;
    Graph g1(v), g2(v);
    while (e--) {
        int a, b, w; cin >> a >> b >> w;
        --a, --b;
        g1.add_edge(a, b, w);
        g2.add_edge(b, a, w);
    }
    
    g1.dijkstra(x);
    g2.dijkstra(x);

    int ans = 0;
    for (int i = 0; i < v; i++) {
        ans = max<int>(ans, g1.dist[i] + g2.dist[i]);
    }

    cout << ans << endl;

    return 0;
}
