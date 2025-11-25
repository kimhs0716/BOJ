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

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    ll tar = accumulate(arr.begin(), arr.end(), 0LL) / n;
    vvl adj(n);
    for (i=0;i<n-1;i++) {
        ll u, v; cin>>u>>v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vvp in(n), out(n);
    function<ll(ll, ll)> dfs = [&arr, tar, &adj, &in, &out, &dfs](ll cur, ll par) -> ll {
        ll ret = arr[cur] - tar;
        for (ll nxt: adj[cur]) {
            if (nxt == par) continue;
            ll t = dfs(nxt, cur);
            if (t<0) {
                out[cur].push_back({nxt, -t});
                in[nxt].push_back({cur, -t});
            }
            else {
                in[cur].push_back({nxt, t});
                out[nxt].push_back({cur, t});
            }
            ret += t;
        }
        return ret;
    };
    dfs(0, -1);
    // for (i=0;i<n;i++) {
    //     cout<<i<<": ";
    //     for (auto [x, w] : out[i]) cout<<"("<<x<<", "<<w<<") ";
    //     cout<<" / ";
    //     for (auto [x, w] : in[i]) cout<<"("<<x<<", "<<w<<") ";
    //     cout<<endl;
    // }
    vector<array<ll, 3>> ans;
    function<void(ll, ll)> dfs2 = [&in, &out, &ans, &dfs2](ll cur, ll par) {
        for (auto [x, w] : in[cur]) {
            if (x==par) continue;
            dfs2(x, cur);
        }
        for (auto [x, w] : out[cur]) {
            if (w) ans.push_back({cur, x, w});
            if (x!=par) dfs2(x, cur);
        }
    };
    dfs2(0, -1);
    cout<<ans.size()<<endl;
    for (auto [a, b, c] : ans) cout<<a+1<<' '<<b+1<<' '<<c<<endl;
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

