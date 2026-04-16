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
    struct Edge {
        ll to, cap, rev;
    };
    ll n, s, t;
    vl level, it;
    vector<vector<Edge>> adj;
    Dinic(ll n, ll s, ll t, vvp &tadj) : n(n), s(s), t(t), adj(n) {
        for (ll i=0;i<n;i++) {
            for (auto [to, w] : tadj[i])
                add_edge(i, to, w);
        }
    }
    Dinic(ll n, ll s, ll t) : n(n), s(s), t(t), adj(n) {}
    void add_edge(ll u, ll v, ll w) {
        Edge a(v, w, adj[v].size());
        Edge b(u, 0, adj[u].size());
        adj[u].push_back(a);
        adj[v].push_back(b);
    }
    void BFS() {
        level.assign(n, -1);
        queue<ll> q;
        q.push(s);
        level[s] = 0;
        ll time = 0;
        while (q.size()) {
            ll sz = q.size();
            time++;
            while (sz--) {
                ll cur = q.front(); q.pop();
                for (auto [nxt, w, rev] : adj[cur]) {
                    if (!w) continue;
                    if (level[nxt] != -1) continue;
                    level[nxt] = time;
                    q.push(nxt);
                }
            }
        }
    }
    ll dfs(ll cur, ll f) {
        if (cur == t) return f;
        for (ll &i = it[cur]; i<adj[cur].size(); i++) {
            auto &[to, cap, rev] = adj[cur][i];
            if (cap>0 && level[to] == level[cur]+1) {
                ll ret = dfs(to, min(f, cap));
                if (ret>0) {
                    cap -= ret;
                    adj[to][rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    ll max_flow() {
        ll ret=0;
        while (true) {
            BFS();
            it.assign(n, 0);
            if (level[t] == -1) return ret;
            // cout<<level<<endl;
            while (true) {
                ll x = dfs(s, INF);
                if (!x) break;
                ret += x;
            }
        }
    }
};

ll max_matching(ll n, ll m, vvl &tadj) {
    Dinic d(n+m+2, 0, n+m+1);
    for (ll l=0;l<n;l++) {
        for (auto r : tadj[l]) {
            d.add_edge(l+1, r+n+1, 1);
        }
    }
    for (ll l=0;l<n;l++) d.add_edge(0, l+1, 2);
    for (ll r=0;r<m;r++) d.add_edge(r+n+1, n+m+1, 1);
    return d.max_flow();
}

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    map<char, ll> node_idx;
    ll n, m; cin>>n>>m;
    vvl adj(n);
    for (i=0;i<n;i++) {
        ll t; cin>>t;
        while (t--) {
            ll x; cin>>x;
            adj[i].push_back(x-1);
        }
    }
    cout<<max_matching(n, m, adj)<<endl;
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

