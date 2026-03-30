#include <bits/stdc++.h>

#include <utility>
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
constexpr ll MAX = 500'000;
constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    vvp adj(n);
    for (i=0;i<n-1;i++) {
        ll u, v, w; cin>>u>>v>>w;
        --u; --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vl dist(n), depth(n);
    vvl anc(17, vl(n));
    function<void(ll, ll)> dfs = [&adj, &anc, &dist, &depth, &dfs](ll cur, ll par) {
        anc[0][cur] = par;
        for (auto [nxt, w] : adj[cur]) {
            if (nxt == par) continue;
            dist[nxt] = dist[cur] + w;
            depth[nxt] = depth[cur]+1;
            dfs(nxt, cur);
        }
    };
    dfs(0, 0);
    // cout<<dist<<endl;
    // cout<<anc[0]<<endl;
    for (i=1;i<17;i++) {
        for (j=0;j<n;j++)
            anc[i][j] = anc[i-1][anc[i-1][j]];
    }
    function<ll(ll, ll)> lca = [&anc, &depth](ll u, ll v) {
        if (depth[u] > depth[v]) swap(u, v);
        ll diff = depth[v] - depth[u];
        for (ll i=0;i<17;i++) {
            if (diff&1) v = anc[i][v];
            diff >>= 1;
        }
        if (u==v) return u;
        for (ll i=16;i>=0;i--) {
            ll pu = anc[i][u];
            ll pv = anc[i][v];
            if (pu != pv) {
                u = pu;
                v = pv;
            }
        }
        return anc[0][u];
    };
    ll q; cin>>q;
    while (q--) {
        ll a, b, c, d; cin>>a>>b>>c;
        if (a==1) {
            --b; --c;
            ll l = lca(b, c);
            cout<<dist[b]+dist[c]-2*dist[l]<<endl;
        }
        else {
            cin>>d;
            --b; --c;
            ll l = lca(b, c);
            if (d > depth[b]-depth[l]+1) {
                d = depth[b] + depth[c] - 2*depth[l] - d + 2;
                b = c;
            }
            --d;
            for (i=0;i<17;i++) {
                if (d&1) b = anc[i][b];
                d >>= 1;
            }
            cout<<b+1<<endl;;
        }
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
