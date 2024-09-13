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

int _min(pii& p) {
    return (p.first < p.second) ? p.first : p.second;
}

class Graph {
public:
    int n;
    vector<vi> children;
    vector<set<int>> edges;
    
    Graph(int n) : n(n) {
        children = vector<vi>(n + 1);
        edges = vector<set<int>>(n + 1);
    }

    void add_edge(int u, int v) {
        edges[u].insert(v);
        edges[v].insert(u);
    }

    void dfs(int v) {
        vi st;
        set<int> visited;
        st.push_back(v);
        visited.insert(v);
        while (!st.empty()) {
            v = st.back();
            st.pop_back();
            for (int nxt : edges[v]) {
                if (visited.find(nxt) != visited.end()) continue;
                visited.insert(nxt);
                st.push_back(nxt);
                children[v].push_back(nxt);
            }
        }
    }
};

pii& solve(Graph& g, int u, vector<pii>& dp) {
    if (dp[u].first == -1) {
        dp[u].first = 0;
        for (int c : g.children[u])
            dp[u].first += solve(g, c, dp).second;
    }

    if (dp[u].second == -1) {
        dp[u].second = 1;
        for (int c : g.children[u])
            dp[u].second += _min(solve(g, c, dp));
    }

    return dp[u];
}

int main() {
    FASTIO;
    _init();

    int n; cin >> n;
    Graph g(n);
    vector<pii> dp(n + 1, pii(-1, -1));

    while (n --> 1) {
        int u, v; cin >> u >> v;
        g.add_edge(u, v);
    }

    g.dfs(1);
    cout << _min(solve(g, 1, dp)) << endl;

    return 0;
}
