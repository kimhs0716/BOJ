#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;
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
ostream& operator<<(ostream &os, vector<T> &arr) {
    os<<'(';
    for (auto &x: arr) os<<x<<' ';
    return os<<')';
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

void solve(ll testcase) {
    ll i, j;
    ll n, m; cin>>n>>m;
    vvl adj(n);
    while (m--) {
        ll u, v; cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    bool ans=true;
    vl color(n, -1);
    function<void(ll, ll)> dfs = [&adj, &ans, &color, &dfs](ll cur, ll c) {
        color[cur] = c;
        for (ll nxt: adj[cur]) {
            if (color[nxt] == -1)
                dfs(nxt, !c);
            else if (color[nxt] == c) {
                ans = false;
                return;
            }
        }
    };
    for (i=0;i<n;i++) {
        if (color[i]==-1) dfs(i, 0);
    }
    cout<<"Scenario #"<<testcase<<":\n";
    if (ans) cout<<"No suspicious bugs found!";
    else cout<<"Suspicious bugs found!";
    cout<<endl<<endl;
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