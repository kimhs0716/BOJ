#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vp = vector<pll>;

vector<int> solution(int n, vector<vector<int>> roads) {
    constexpr ll INF = 1e15;
    vector<vector<array<ll, 3>>> adj(n);
    map<pll, ll> edge_id;
    for (int i=0; i<roads.size(); i++) {
        int u = roads[i][0]-1;
        int v = roads[i][1]-1;
        int l = roads[i][2], t = roads[i][3];
        adj[u].push_back({v, l, l+t});
        adj[v].push_back({u, l, l+t});
        edge_id[{min(u, v), max(u, v)}] = i+1;
    }
    vl dist(n, INF);
    vector<vp> prev(n);
    dist[0] = 0;
    priority_queue<pll, vp, greater<>> pq;
    pq.push({0, 0});
    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (dist[u] != d) continue;
        for (auto [v, w1, w2] : adj[u]) {
            if (dist[v] > d+w2) {
                prev[v].clear();
                dist[v] = d+w2;
                pq.push({d+w2, v});
            }
            if (dist[v] == d+w2) prev[v].push_back({u, w2});
        }
    }
    set<int> selected;
    // for (int i=0; i<n; i++) cout<<i<<": "<<dist[i]<<endl;
    pq.push({0, n-1});
    vl vis(n);
    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (prev[u].size()==1 && pq.empty()) {
            auto [v, w] = prev[u][0];
            selected.insert(edge_id[{min(u, v), max(u, v)}]);
        }
        for (auto [v, w] : prev[u]) {
            if (vis[v]) continue;
            vis[v] = 1;
            pq.push({d+w, v});
        }
    }
    vl dist2(n, INF);
    dist2[n-1] = 0;
    pq.push({0, n-1});
    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (dist2[u] != d) continue;
        for (auto [v, w1, w2] : adj[u]) {
            if (dist2[v] > d+w2) {
                dist2[v] = d+w2;
                pq.push({d+w2, v});
            }
        }
    }
    for (int i=0; i<roads.size(); i++) {
        int u = roads[i][0]-1;
        int v = roads[i][1]-1;
        int l = roads[i][2], t = roads[i][3];
        if (dist[u]+l+dist2[v] < dist[n-1] || dist[v]+l+dist2[u] < dist[n-1])
            selected.insert(i+1);
    }
    vector<int> ans;
    for (auto x : selected) ans.push_back(x);
    if (ans.empty()) ans.push_back(-1);
    return ans;
}