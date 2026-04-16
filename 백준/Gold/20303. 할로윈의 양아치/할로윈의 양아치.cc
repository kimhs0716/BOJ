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

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n, m; cin>>n>>m>>k;
    vl candy(n); cin>>candy;
    vvl adj(n);
    while (m--) {
        ll u, v; cin>>u>>v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vp arr;
    vl vis(n);
    function<pll(ll)> f = [&adj, &candy, &vis, &f](ll cur) -> pll {
        ll w = candy[cur], c = 1;
        for (ll nxt: adj[cur]) {
            if (vis[nxt]) continue;
            vis[nxt] = 1;
            auto [ww, cc] = f(nxt);
            w += ww;
            c += cc;
        }
        return {w, c};
    };
    for (i=0;i<n;i++) {
        if (!vis[i]) {
            vis[i] = 1;
            arr.push_back(f(i));
        }
    }
    // for (auto [w, c] : arr) cout<<w<<' '<<c<<endl;
    vl dp(k, -1);
    dp[0] = 0;
    for (auto [w, c] : arr) {
        for (i=k-1;i>=c;i--) {
            if (dp[i-c]!=-1) dp[i] = max(dp[i], dp[i-c] + w);
        }
        // cout<<dp<<endl;
    }
    cout<<*max_element(dp.begin(), dp.end())<<endl;
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

