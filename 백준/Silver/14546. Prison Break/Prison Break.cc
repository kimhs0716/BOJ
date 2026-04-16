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
    for (auto &x: arr) os<<x<<' ';
    return os;
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

ll dr[] = {0, 1, 0, -1};
ll dc[] = {1, 0, -1, 0};

void solve(ll tc){
    ll i, j;
    ll c, r, fc, fr, gc,  gr; cin>>c>>r>>fc>>fr>>gc>>gr;
    fc--, gc--;
    fr=r-fr, gr=r-gr;
    vvl arr(r, vl(c)), vis(r, vl(c));
    for (auto &x: arr) for (auto &y: x) {
        char t; cin>>t;
        y=(t=='+');
    }
    function<bool(ll, ll)> dfs = [&](ll cr, ll cc) -> bool {
        // cout<<cr<<' '<<cc<<endl;
        if (cr==gr && cc==gc) return true;
        for (ll i=0;i<4;i++) {
            ll nr = cr + dr[i];
            ll nc = cc + dc[i];
            if (nr<0 || nr>=r) continue;
            if (nc<0 || nc>=c) continue;
            if (arr[nr][nc] != arr[cr][cc]) continue;
            if (vis[nr][nc]) continue;
            vis[nr][nc]=1;
            if (dfs(nr, nc)) return true;
        }
        return false;
    };
    vis[fr][fc]=1;
    if (dfs(fr, fc)) cout<<"YES\n";
    else cout<<"NO\n";
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