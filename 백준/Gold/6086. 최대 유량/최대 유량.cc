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
ostream& operator<<(ostream &os, vector<T> &arr) {
    if (arr.size()==0) return os<<"()";
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) os<<arr[i]<<' ';
    if (arr.size()) os<<arr.back();
    return os<<')';
}

// constexpr ll MOD = 1e9+7;
constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e18;
constexpr ll MAX = 300'001;

struct Dinic {
    ll n, s, t;
    vl level;
    vvp &adj;
    Dinic(ll n, ll s, ll t, vvp &adj) : n(n), s(s), t(t), adj(adj) {}
    void BFS() {
        queue<ll> q;
        q.push(s);
        level[s] = 0;
        ll time = 0;
        while (q.size()) {
            ll sz = q.size();
            time++;
            while (sz--) {
                ll cur = q.front(); q.pop();
                for (auto [nxt, w] : adj[cur]) {
                    if (!w) continue;
                    if (level[nxt] != -1) continue;
                    level[nxt] = time;
                    q.push(nxt);
                }
            }
        }
    }
    ll dfs(ll cur, ll f, vl &vis) {
        if (cur == t) return f;
        for (auto &[nxt, w] : adj[cur]) {
            if (level[nxt] != level[cur]+1) continue;
            if (vis[nxt]) continue;
            if (!w) continue;
            vis[nxt] = 1;
            ll mf = dfs(nxt, min(f, w), vis);
            if (mf != -1) {
                w -= mf;
                return mf;
            }
        }
        return -1;
    }
    ll max_flow() {
        vl vis(n);
        ll ret=0;
        while (true) {
            level.assign(n, -1);
            BFS();
            if (level[t] == -1) return ret;
            // cout<<level<<endl;
            vis.assign(n, 0);
            ret += dfs(s, INF, vis);
        }
    }
};

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    map<char, ll> node_idx;
    ll n; cin>>n;
    vvp adj(n);
    while (n--) {
        char u, v; ll w; cin>>u>>v>>w;
        if (!node_idx.contains(u)) node_idx[u] = node_idx.size();
        if (!node_idx.contains(v)) node_idx[v] = node_idx.size();
        u = node_idx[u];
        v = node_idx[v];
        if (u == adj.size()) adj.push_back(vp{});
        adj[u].push_back({v, w});
        if (v == adj.size()) adj.push_back(vp{});
        adj[v].push_back({u, w});
    }
    ll s = node_idx['A'];
    ll t = node_idx['Z'];
    Dinic dinic(node_idx.size(), s, t, adj);
    cout<<dinic.max_flow()<<endl;
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

