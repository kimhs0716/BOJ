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

using elem = array<ll, 3>;

vl dijk(vvp &adj, ll s, ll d) {
    ll n = adj.size();
    vvl dist(n, vl(n, INF));
    priority_queue<elem> q;
    dist[s][s] = 0;
    q.push({0, 0, s});
    while (q.size()) {
        auto [d, cnt, cur] = q.top();
        // cout<<d<<' '<<cnt<<' '<<cur<<endl;
        q.pop();
        d = -d;
        if (cnt==n-1 || dist[cur][cnt] < d) continue;
        for (auto [nxt, w] : adj[cur]) {
            if (dist[nxt][cnt+1] > d + w) {
                dist[nxt][cnt+1] = d + w;
                q.push({-(d+w), cnt+1, nxt});
            }
        }
    }
    return dist[d];
}

void preprocess() {
    ll i, j, k;
}

void solve(ll tc) {
    ll i, j;
    ll n, m, k; cin>>n>>m>>k;
    ll s, d; cin>>s>>d;
    vvp adj(n);
    while (m--) {
        ll a, b, c; cin>>a>>b>>c;
        adj[a-1].push_back({b-1, c});
        adj[b-1].push_back({a-1, c});
    }
    vl dist = dijk(adj, s-1, d-1);
    // cout<<dist<<endl;
    ll tax = 0;
    k++;
    while (k--) {
        ll ans = INF;
        for (i=0;i<n;i++) {
            ans = min(ans, dist[i] + tax*i);
        }
        cout<<ans<<endl;
        ll t; cin>>t;
        tax += t;
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

