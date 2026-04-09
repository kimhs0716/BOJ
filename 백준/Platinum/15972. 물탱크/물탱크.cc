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
constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll r, c, h; cin>>r>>c>>h;
    vvp adj(r*c+1);
    for (i=0;i<c;i++) {
        ll x; cin>>x;
        if (x!=-1) {
            adj[0].push_back({i+1, x});
        }
    }
    for (i=0;i<r-1;i++) {
        for (j=0;j<c;j++) {
            ll x; cin>>x;
            if (x==-1) continue;
            ll a = c*i+j+1;
            ll b = a+c;
            adj[a].push_back({b, x});
            adj[b].push_back({a, x});
        }
    }
    for (i=0;i<c;i++) {
        ll x; cin>>x;
        if (x!=-1) {
            adj[0].push_back({(r-1)*c+i+1, x});
        }
    }
    for (i=0;i<r;i++) {
        ll x; cin>>x;
        if (x!=-1) adj[0].push_back({c*i+1, x});
        for (j=0;j<c-1;j++) {
            cin>>x;
            if (x!=-1) {
                ll a = i*c+j+1;
                ll b = a+1;
                adj[a].push_back({b, x});
                adj[b].push_back({a, x});
            }
        }
        cin>>x;
        if (x!=-1) adj[0].push_back({c*i+c, x});
    }
    // for (auto &x : adj) {
    //     for (auto [y, z] : x) cout<<y<<'|'<<z<<' ';
    //     cout<<endl;
    // }
    vl dist(r*c+1, h);
    priority_queue<pll, vp, greater<>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (dist[u] != d) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > max(w, d)) {
                dist[v] = max(w, d);
                pq.push({max(w, d), v});
            }
        }
    }
    // cout<<dist<<endl;
    cout<<accumulate(dist.begin(), dist.end(), 0LL)<<endl;
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
