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

// constexpr ll MOD = 1e9+7;
constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e18;
constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll n, s; cin>>n>>s;
    vvp adj(n);
    for (i=0;i<n-1;i++) {
        ll a, b, c; cin>>a>>b>>c;
        --a; --b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vl tunnel;
    function<void(ll, ll, ll)> dfs = [&adj, &tunnel, &dfs](ll cur, ll par, ll mh) {
        bool is_leaf = true;
        for (auto [nxt, h] : adj[cur]) {
            if (nxt == par) continue;
            is_leaf = false;
            dfs(nxt, cur, min(mh, h));
        }
        if (is_leaf) tunnel.push_back(mh);
    };
    dfs(s-1, -1, INF);
    ll m; cin>>m;
    vl miner(m); cin>>miner;
    sort(miner.begin(), miner.end());
    sort(tunnel.begin(), tunnel.end());
    // cout<<tunnel<<endl;
    // cout<<miner<<endl;
    ll ans = 0;
    n = tunnel.size();
    i=0; j=0;
    while (i<n && j<m) {
        while (i<n && tunnel[i]<miner[j]) i++;
        if (i==n) break;
        ans++;
        j++;
        i++;
    }
    cout<<ans<<endl;
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
