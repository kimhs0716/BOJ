#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;
using vd = vector<ld>;
using ull = unsigned long long;
using vp = vector<pll>;
using vvp = vector<vp>;
using tlll = array<ll, 3>;

#define endl '\n'

void setup() {
#ifdef KIMHS
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}

template <typename T>
istream& operator>>(istream &is, vector<T> &arr) {
    for (auto &x: arr) is>>x;
    return is;
}

template <typename T>
ostream& operator<<(ostream &os, vector<T> arr) {
    if (arr.size()==0) return os<<"()";
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) os<<arr[i]<<' ';
    if (arr.size()) os<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e15;

vl dijkstra(vector<map<ll, ll>> &adj, ll s) {
    ll n = adj.size();
    vl dist(n, INF), vis(n);
    dist[s] = 0;
    vis[s] = 1;
    priority_queue<pll, vp, greater<>> pq;
    pq.push({0, s});
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        vis[u] = 1;
        for (auto [nxt, w] : adj[u]) {
            if (vis[nxt]) continue;
            if (dist[u]+w < dist[nxt]) {
                dist[nxt] = dist[u] + w;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    for (auto &x: dist) if (x==INF) x=-1;
    return dist;
}

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n, m; cin>>n>>m;
    ll s; cin>>s;
    vector<map<ll, ll>> adj(n);
    while (m--) {
        ll u, v, w; cin>>u>>v>>w;
        --u; --v;
        if (adj[u].contains(v)) adj[u][v] = min(adj[u][v], w);
        else adj[u][v] = w;
    }
    vl dist = dijkstra(adj, s-1);
    for (auto x: dist) {
        if (x==-1) cout<<"INF\n";
        else cout<<x<<endl;
    }
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    // cin >> testcase;
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
    }
}

