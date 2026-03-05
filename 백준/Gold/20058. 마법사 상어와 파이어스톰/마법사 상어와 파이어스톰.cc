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

void rotate(vvl &arr, ll l) {
    ll n = arr.size();
    vvl temp(l, vl(l));
    for (ll r=0;r<n;r+=l) {
        for (ll c=0;c<n;c+=l) {
            for (ll i=0;i<l;i++) {
                for (ll j=0;j<l;j++) {
                    temp[j][l-i-1] = arr[r+i][c+j];
                }
            }
            for (ll i=0;i<l;i++) {
                for (ll j=0;j<l;j++) {
                    arr[r+i][c+j] = temp[i][j];
                }
            }
        }
    }
}

ll dr[] = {0, 1, 0, -1};
ll dc[] = {1, 0, -1, 0};
void reduce(vvl &arr) {
    ll n = arr.size();
    vvl temp(n, vl(n));
    for (ll r=0;r<n;r++) {
        for (ll c=0;c<n;c++) {
            ll t = 0;
            for (ll i=0;i<4;i++) {
                ll nr = r + dr[i];
                ll nc = c + dc[i];
                if (nr<0 || nr>=n) continue;
                if (nc<0 || nc>=n) continue;
                if (arr[nr][nc]) t++;
            }
            temp[r][c] = arr[r][c];
            if (temp[r][c] && t<=2) temp[r][c]--;
        }
    }
    swap(arr, temp);
}

ll dfs(vvl &arr, vvl &vis, ll r, ll c) {
    ll ret = 1;
    ll n = arr.size();
    for (ll i=0;i<4;i++) {
        ll nr = r+dr[i];
        ll nc = c+dc[i];
        if (nr<0 || nr>=n) continue;
        if (nc<0 || nc>=n) continue;
        if (vis[nr][nc]) continue;
        if (arr[nr][nc]==0) continue;
        vis[nr][nc] = 1;
        ret += dfs(arr, vis, nr, nc);
    }
    return ret;
}

void solve(ll tc){
    ll i, j;
    ll n, q; cin>>n>>q;
    n = (1LL<<n);
    vvl arr(n, vl(n)); cin>>arr;
    while (q--) {
        ll x; cin>>x;
        x = (1LL<<x);
        rotate(arr, x);
        reduce(arr);
    }
    ll sum = 0, ans = 0;
    vvl vis(n, vl(n));
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            sum += arr[i][j];
            if (vis[i][j]) continue;
            if (arr[i][j]==0) continue;
            vis[i][j] = 1;
            ll t = dfs(arr, vis, i, j);
            ans = max(ans, t);
        }
    }
    cout<<sum<<endl;
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
