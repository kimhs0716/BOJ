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
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n, m; cin>>n>>m;
    vvl adj(n);
    while (m--) {
        ll u, v; cin>>u>>v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vl color(n, -1);
    function<pll(ll, ll)> dfs = [&adj, &color, &dfs](ll cur, ll c) -> pll {
        color[cur] = c;
        ll a=0, b=0;
        if (c) a++;
        else b++;
        for (ll nxt: adj[cur]) {
            if (color[nxt] == -1) {
                auto [x, y] = dfs(nxt, !c);
                if (x==-1) return {-1, -1};
                a += x;
                b += y;
            }
            else {
                if (color[nxt] == c) return {-1, -1};
            }
        }
        return {a, b};
    };
    ll ans = 0;
    for (i=0;i<n;i++) {
        if (color[i]==-1) {
            color[i] = 0;
            auto [x, y] = dfs(i, 0);
            ans += max(x, y);
            if (x==-1) {
                cout<<"-1\n";
                return;
            }
        }
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

