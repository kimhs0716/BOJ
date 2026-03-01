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
constexpr ll INF = 1e15;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    vvl adj(n);
    for (i=0;i<n-1;i++) {
        ll u, v; cin>>u>>v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vl dp(n), par(n);
    function<void(ll, ll)> dfs = [&adj, &dp, &par, &dfs](ll cur, ll p) {
        dp[cur] = 1;
        par[cur] = p;
        for (ll nxt : adj[cur]) {
            if (nxt == p) continue;
            dfs(nxt, cur);
            dp[cur] += dp[nxt];
        }
    };
    dfs(0, -1);
    // cout<<dp<<endl;
    // cout<<par<<endl;
    ll cent = 0;
    while (true) {
        vp temp;
        ll s = 0;
        for (auto x: adj[cent]) {
            if (x==par[cent]) continue;
            temp.push_back({dp[x], x});
            s += dp[x];
        }
        temp.push_back({n-dp[cent], par[cent]});
        sort(temp.begin(), temp.end());
        if (temp.back().first > n/2) {
            cent = temp.back().second;
        }
        else break;
    }
    // cout<<cent<<endl;
    dfs(cent, -1);
    function<bool(ll)> check = [&adj, &dp, &par, n, &check](ll cur) {
        vl temp;
        for (auto x: adj[cur]) {
            if (x==par[cur]) continue;
            temp.push_back(dp[x]);
            if (!check(x)) return false;
        }
        sort(temp.begin(), temp.end());
        bool flag = true;
        ll s = 1;
        for (auto c : temp) {
            if (c>s) {
                flag = false;
                break;
            }
            s += c;
        }
        return flag;
    };
    if (check(cent)) {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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
