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
constexpr ll INF = 1e15;

vl dijk(vvp &adj, ll s) {
    ll n = adj.size();
    vl dist(n, INF);
    dist[s] = 0;
    priority_queue<pll, vp, greater<>> pq;
    vl vis(n);
    pq.push({0, s});
    while (pq.size()) {
        auto [d, x] = pq.top(); pq.pop();
        if (vis[x]) continue;
        for (auto [nxt, w] : adj[x]) {
            if (dist[nxt] > dist[x] + w) {
                dist[nxt] = dist[x] + w;
                pq.push({dist[nxt], nxt});
            }
        }
        vis[x] = 1;
    }
    // for (auto &x: dist) if (x==INF) x = -1;
    return dist;
}

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n, m, x, s; cin>>n>>m>>x>>s;
    vvp adj(n);
    while (m--) {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vl dist = dijk(adj, s);
    priority_queue<ll> pq;
    for (auto d: dist) pq.push(d);
    ll ans = 0, cur = 0;
    while (pq.size()) {
        ll t = pq.top();
        if (cur+2*t<=x) {
            cur += 2*t;
            pq.pop();
        }
        else if (2*t > x) {
            cout<<"-1\n";
            return;
        }
        else {
            ans++;
            cur = 0;
        }
    }
    if (cur) ans++;
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

