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

void preprocess() {
    ll i, j;
}

ll dr[] = {1, 0, -1, 0};
ll dc[] = {0, 1, 0, -1};
void solve(ll tc) {
    ll i, j;
    ll r, c; cin>>r>>c;
    vvl a(r, vl(c)), b(r, vl(c));
    cin>>a>>b;
    vp diff;
    for (i=0;i<r;i++)
        for (j=0;j<c;j++)
            if (a[i][j] != b[i][j]) diff.push_back({i, j});
    if (diff.empty()) {
        cout<<"YES\n";
        return;
    }
    auto [x, y] = diff[0];
    ll from = a[x][y], to = b[x][y];
    for (auto [x, y] : diff) {
        if (a[x][y] != from || b[x][y] != to) {
            cout<<"NO\n";
            return;
        }
    }
    vp cluster;
    vvl vis(r, vl(c));
    function<void(ll, ll)> find = [&vis, &cluster, &a, r, c, &find](ll rr, ll cc) {
        cluster.push_back({rr, cc});
        for (ll i=0;i<4;i++) {
            ll nr = rr+dr[i], nc = cc+dc[i];
            if (nr<0 || nr>=r) continue;
            if (nc<0 || nc>=c) continue;
            if (vis[nr][nc]) continue;
            vis[nr][nc] = 1;
            if (a[nr][nc] != a[rr][cc]) continue;
            find(nr, nc);
        }
    };
    vis[x][y] = 1;
    find(x, y);
    sort(cluster.begin(), cluster.end());
    if (diff.size() != cluster.size()) {
        cout<<"NO\n";
        return;
    }
    for (i=0;i<diff.size();i++) {
        if (diff[i] != cluster[i]) {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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
