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
constexpr ll INF = (ll)1e18+1;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll n, m; cin>>n>>m;
    ll s, a, b; cin>>s>>a>>b;
    vvp adj(n);
    while (m--) {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vvl prev(n);
    vl dist(n, INF);
    dist[s] = 0;
    priority_queue<pll, vp, greater<pll>> pq;
    pq.push({0, s});
    while (pq.size()) {
        auto [d, cur] = pq.top(); pq.pop();
        if (dist[cur] != d) continue;
        for (auto [nxt, w] : adj[cur]) {
            if (d+w < dist[nxt]) {
                dist[nxt] = d+w;
                pq.push({d+w, nxt});
                prev[nxt].clear();
            }
            if (d+w == dist[nxt]) prev[nxt].push_back(cur);
        }
    }
    // cout<<dist<<endl;
    // for (i=0;i<n;i++) {
    //     cout<<i<<": "<<prev[i]<<endl;
    // }
    vl arr(n);
    queue<ll> q;
    q.push(a);
    arr[a] |= 1;
    while (q.size()) {
        ll cur = q.front(); q.pop();
        for (ll p: prev[cur]) {
            if (arr[p]&1) continue;
            arr[p] |= 1;
            q.push(p);
        }
    }
    q.push(b);
    arr[b] |= 2;
    while (q.size()) {
        ll cur = q.front(); q.pop();
        for (ll p: prev[cur]) {
            if ((arr[p]>>1)&1) continue;
            arr[p] |= 2;
            q.push(p);
        }
    }
    // cout<<arr<<endl;
    dist = vl(n, INF);
    dist[s] = 0;
    pq.push({0, s});
    while (pq.size()) {
        auto [d, cur] = pq.top(); pq.pop();
        if (dist[cur] != d) continue;
        for (auto [nxt, w] : adj[cur]) {
            if (arr[nxt] != 3) continue;
            if (d+w < dist[nxt]) {
                dist[nxt] = d+w;
                pq.push({d+w, nxt});
            }
        }
    }
    for (auto &x: dist) if (x==INF) x = -1;
    // cout<<dist<<endl;
    cout<<*max_element(dist.begin(), dist.end())<<endl;
    // cout<<endl;
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    cin >> testcase;
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
    }
}
