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
constexpr ll INF = 1e15;
constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll c, r, mc, mr; cin>>c>>r>>mc>>mr;
    vector<string> arr(r); cin>>arr;
    ll dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    ll dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    vvl dist(r, vl(c, -1));
    queue<pll> q;
    ll sr = r-mr;
    ll sc = mc-1;
    q.push({sr, sc});
    dist[sr][sc] = 0;
    ll ans = 0;
    while (q.size()) {
        auto [cr, cc] = q.front();
        q.pop();
        for (i=0;i<8;i++) {
            ll nr = cr+dr[i];
            ll nc = cc+dc[i];
            if (nr<0 || nr>=r) continue;
            if (nc<0 || nc>=c) continue;
            if (arr[nr][nc]=='*') continue;
            if (dist[nr][nc] != -1) continue;
            dist[nr][nc] = dist[cr][cc]+1;
            q.push({nr, nc});
        }
        ans = dist[cr][cc];
    }
    cout<<ans<<endl;
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    // cin >> testcase;
    for (ll i = 1; i     <= testcase; i++) {
        solve(i);
    }
}
