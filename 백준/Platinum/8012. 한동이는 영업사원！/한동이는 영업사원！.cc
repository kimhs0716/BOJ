#include <bits/stdc++.h>

#include <utility>
#pragma GCC optimize ("O0,unroll-loops")
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
    vvl adj(n);
    vvl anc(n, vl(15));
    vl par(n), depth(n);
    for (i=0;i<n-1;i++) {
        ll x, y; cin>>x>>y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll k; cin>>k; --k;
    ll cur; cin>>cur; --cur;
    function<void(ll, ll, ll)> dfs = [&adj, &par, &depth, &dfs](ll cur, ll p, ll d) {
        par[cur] = p;
        depth[cur] = d;
        for (ll nxt: adj[cur]) {
            if (nxt==p) continue;
            dfs(nxt, cur, d+1);
        }
    };
    dfs(cur, cur, 0);
    // cout<<par<<endl;
    for (i=0;i<n;i++) anc[i][0] = par[i];
    for (j=1;j<15;j++) {
        for (i=0;i<n;i++) anc[i][j] = anc[anc[i][j-1]][j-1];
    }
    // for (j=0;j<15;j++) {
    //     for (i=0;i<n;i++) cout<<anc[i][j]<<' ';
    //     cout<<endl;
    // }
    ll ans = 0;
    function<ll(ll, ll)> dist = [&anc, &depth](ll a, ll b) {
        ll ret = depth[a] + depth[b];
        if (depth[a] < depth[b]) swap(a, b);
        ll d = depth[a] - depth[b];
        while (d) {
            ll k = __builtin_ctzll(d);
            a = anc[a][k];
            d ^= (1LL<<k);
        }
        while (a!=b) {
            if (anc[a][0] == anc[b][0]) {
                a = b = anc[a][0];
                break;
            }
            for (ll i=1;i<15;i++) {
                if (anc[a][i] == anc[b][i]) {
                    a = anc[a][i-1];
                    b = anc[b][i-1];
                    break;
                }
            }
        }
        return ret - 2*depth[a];
    };
    while (k--) {
        ll nxt; cin>>nxt; --nxt;
        ans += dist(cur, nxt);
        cur = nxt;
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

