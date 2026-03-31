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
    int i, j;
    ll n; cin>>n;
    vvl adj(n);
    for (i=0;i<n-1;i++) {
        ll u, v; cin>>u>>v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vl S(n), vis(n);
    function<ll(ll, ll)> dfs = [&adj, &S, &vis, &dfs](ll cur, ll par) {
        ll ret = 1;
        vis[cur] = 1;
        for (ll nxt : adj[cur]) {
            if (nxt == par) continue;
            if (S[nxt]==0) continue;
            ret += dfs(nxt, cur);
        }
        return ret;
    };
    ll q; cin>>q;
    while (q--) {
        ll k; cin>>k;
        for (i=0;i<n;i++) S[i] = vis[i] = 0;
        while (k--) {
            ll x; cin>>x;
            S[x-1] = 1;
        }
        ll ans = 0;
        for (i=0;i<n;i++) {
            if (S[i] && vis[i]==0) {
                ll cur = dfs(i, -1);
                ans += cur * (cur-1) / 2;
            }
        }
        cout<<ans<<endl;
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
