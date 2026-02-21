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
    vvl adj(n+1);
    while (m--) {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll k; cin>>k;
    set<ll> s;
    while (k--) {
        ll x; cin>>x;
        s.insert(x);
    }
    vl ans;
    for (i=1;i<=n;i++) {
        if (!s.contains(i)) continue;
        bool flag = true;
        for (ll nxt: adj[i]) {
            flag &= s.contains(nxt);
            if (!flag) break;
        }
        if (!flag) continue;
        ans.push_back(i);
    }
    vl arr(n+1);
    for (auto x: ans) {
        arr[x] = 1;
        for (ll nxt: adj[x]) arr[nxt] = 1;
    }
    for (i=1;i<=n;i++) {
        if (s.contains(i) ^ arr[i]) {
            cout<<"-1\n";
            return;
        }
    }
    cout<<ans.size()<<endl;
    for (auto x: ans) cout<<x<<' '; cout<<endl;
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
