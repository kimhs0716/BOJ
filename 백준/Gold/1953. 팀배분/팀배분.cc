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
    ll n; cin>>n;
    vvl adj(n+1);
    for (i=1;i<=n;i++) {
        ll k; cin>>k;
        while (k--) {
            ll x; cin>>x;
            adj[i].push_back(x);
        }
    }
    vl color(n+1, -1);
    function<bool(ll, ll)> dfs = [&adj, &color, &dfs](ll cur, ll col) {
        for (ll nxt: adj[cur]) {
            if (color[nxt] == color[cur]) return false;
            if (color[nxt] == -1) {
                color[nxt] = !col;
                if (!dfs(nxt, !col)) return false;
            }
        }
        return true;
    };
    ll c = 0;
    for (i=1;i<=n;i++) {
        if (color[i]==-1) {
            color[i] = c;
            dfs(i, c);
            c = !c;
        }
    }
    vl ans1, ans2;
    for (i=1;i<=n;i++)
        if (color[i]) ans1.push_back(i);
        else ans2.push_back(i);
    cout<<ans1.size()<<endl;
    for (auto x: ans1) cout<<x<<' '; cout<<endl;
    cout<<ans2.size()<<endl;
    for (auto x: ans2) cout<<x<<' '; cout<<endl;
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
