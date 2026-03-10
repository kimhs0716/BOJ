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

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    vector<tlll> arr(n);
    for (auto &[r, x, y] : arr) cin>>x>>y>>r;
    sort(arr.rbegin(), arr.rend());
    vvl adj(n+1);
    for (i=0;i<n;i++) {
        auto [r, x, y] = arr[i];
        for (j=i-1;j>=0;j--) {
            auto [rr, xx, yy] = arr[j];
            ll d = (x-xx)*(x-xx)+(y-yy)*(y-yy);
            if (d<=(rr-r)*(rr-r)) {
                adj[j+1].push_back(i+1);
                adj[i+1].push_back(j+1);
                break;
            }
        }
        if (adj[i+1].empty()) {
            adj[0].push_back(i+1);
            adj[i+1].push_back(0);
        }
    }
    // for (auto &x : adj) cout<<x<<endl;
    vl dist(n+1);
    function<void(ll, ll)> dfs = [&dist, &adj, &dfs](ll cur, ll par) {
        for (ll nxt : adj[cur]) {
            if (nxt == par) continue;
            dist[nxt] = dist[cur] + 1;
            dfs(nxt, cur);
        }
    };
    dfs(0, -1);
    ll md = *max_element(dist.begin(), dist.end());
    ll s = -1;
    for (i=0;i<=n;i++) if (dist[i]==md) {
        s = i;
        break;
    }
    dist[s] = 0;
    dfs(s, -1);
    cout<<*max_element(dist.begin(), dist.end())<<endl;
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
