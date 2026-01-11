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

void solve(ll tc) {
    ll i, j;
    ll dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};
    ll r, c; cin>>r>>c;
    vector<string> arr(r);
    for (auto &x: arr) cin>>x;
    array<vvl, 1<<6> vis;
    fill(vis.begin(), vis.end(), vvl(r, vl(c)));
    ll cr=-1, cc=-1;
    for (i=0;i<r;i++)
        for (j=0;j<c;j++)
            if (arr[i][j]=='0') {
                cr = i, cc = j;
                arr[i][j] = '.';
                break;
            }
    vis[0][cr][cc] = 1;
    queue<tlll> q;
    q.push({0, cr, cc});
    ll ans = 0;
    while (q.size()) {
        ans++;
        ll sz = q.size();
        while (sz--) {
            auto [key, cr, cc] = q.front();
            q.pop();
            for (i=0;i<4;i++) {
                ll nr = cr+dr[i];
                ll nc = cc+dc[i];
                if (nr<0 || nr>=r) continue;
                if (nc<0 || nc>=c) continue;
                if (vis[key][nr][nc]) continue;
                if (arr[nr][nc]=='#') continue;
                if (arr[nr][nc]=='1') {
                    cout<<ans<<endl;
                    return;
                }
                if (arr[nr][nc]=='.') {
                    vis[key][nr][nc] = 1;
                    q.push({key, nr, nc});
                }
                else if ('A'<=arr[nr][nc] && arr[nr][nc]<='F') {
                    if ((key>>(arr[nr][nc]-'A'))&1) {
                        vis[key][nr][nc] = 1;
                        q.push({key, nr, nc});
                    }
                }
                else {
                    ll nkey = key | (1<<(arr[nr][nc]-'a'));
                    vis[nkey][nr][nc] = 1;
                    q.push({nkey, nr, nc});
                }
            }
        }
    }
    cout<<"-1\n";
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
