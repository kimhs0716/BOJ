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

void preprocess() {
    ll i, j, k;
}

pair<ll, vl> dijk(ll n, ll s, ll e, vector<vector<pll>>& adj, pll ban){
    const ll INF = 1e18;
    vl dis(n,INF), prev(n, -1);
    vector<bool> visit(n, false);
    priority_queue<pll, vector<pll>, greater<pll> > q; // pair(dist, v)
    dis[s] = 0;
    q.push({dis[s], s});
    while (!q.empty()) {
        while (!q.empty() && visit[q.top().second]) q.pop();
        if (q.empty()) break;
        ll next=q.top().second; q.pop();
        visit[next]=1;
        for (ll i=0;i<adj[next].size();++i) {
            if (ban == make_pair(next, adj[next][i].first)) continue;
            if (ban == make_pair(adj[next][i].first, next)) continue;
            if (dis[adj[next][i].first] > dis[next] + adj[next][i].second) {
                prev[adj[next][i].first] = next;
                dis[adj[next][i].first] = dis[next] + adj[next][i].second;
                q.push({dis[adj[next][i].first], adj[next][i].first});
            }
        }
    }
    for(ll i=0;i<n;i++) if(dis[i]==INF) dis[i]=-1;
    vl path;
    for (ll i=e;i!=-1;i=prev[i])
        path.push_back(i);
    reverse(path.begin(), path.end());
    return {dis[e], path};
}

void solve(ll testcase) {
    ll i, j, k;
    ll n, m; cin>>n>>m;
    vvp adj(n);
    map<pll, ll> weight;
    while (m--) {
        ll u, v, w; cin>>u>>v>>w;
        --u; --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        weight[{u, v}] = weight[{v, u}] = w;
    }
    auto [s, path] = dijk(n, 0, n-1, adj, {-1, -1});
    // cout<<s<<endl;
    // for (auto x: path) cout<<x<<' '; cout<<endl;
    ll ans=0;
    for (i=0;i<path.size()-1;i++) {
        auto [cur, _] = dijk(n, 0, n-1, adj, {path[i], path[i+1]});
        // cout<<cur<<endl;
        // for (auto x: _) cout<<x<<' '; cout<<endl;
        if (cur==-1) {
            cout<<"-1\n";
            return;
        }
        ans = max(ans, cur-s);
    }
    cout<<ans<<endl;
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

