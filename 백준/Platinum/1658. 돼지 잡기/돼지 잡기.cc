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
constexpr ll INF = 1e18;

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
        // cout<<u<<' '<<v<<' '<<w<<endl;
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

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n, m; cin>>m>>n;
    Dinic dinic(n*m+n+2, n*m+n, n*m+n+1);
    for (i=0;i<m;i++) {
        ll x; cin>>x;
        dinic.add_edge(n*m+n, i, x);
    }
    for (i=0;i<n;i++) {
        ll x; cin>>x;
        vl arr(x); cin>>arr>>k;
        for (auto &y: arr) {
            y--;
            dinic.add_edge(i*m+y, n*m+i, INF);
        }
        dinic.add_edge(n*m+i, n*m+n+1, k);
        if (i!=n-1) {
            for (j=0;j<m;j++) dinic.add_edge(i*m+j, i*m+m+j, INF);
            for (auto a : arr) {
                for (auto b : arr) {
                    if (a==b) continue;
                    dinic.add_edge(i*m+a, i*m+m+b, INF);
                }
            }
        }
    }
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

