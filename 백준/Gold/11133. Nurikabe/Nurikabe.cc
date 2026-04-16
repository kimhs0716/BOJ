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

// constexpr ll MOD = 1e9+7;
constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e18;

void preprocess() {
    ll i, j, k;
}

ll dr[] = {1, 0, -1, 0};
ll dc[] = {0, 1, 0, -1};
void solve(ll testcase) {
    ll i, j, k;
    ll n, m; cin>>n>>m;
    vector<string> arr(n); cin>>arr;
    vvl vis(n, vl(m));
    function<ll(ll, ll)> f = [&arr, &vis, &f, n, m](ll r, ll c) -> ll {
        ll ret = 1;
        vis[r][c] = 1;
        for (ll i=0;i<4;i++) {
            ll nr = r + dr[i];
            ll nc = c + dc[i];
            if (nr<0 || nr>=n) continue;
            if (nc<0 || nc>=m) continue;
            if (vis[nr][nc]) continue;
            if (arr[nr][nc]=='#') continue;
            if (arr[nr][nc]!='.') return -1;
            vis[nr][nc] = 1;
            ret += f(nr, nc);
        }
        return ret;
    };
    function<ll(ll, ll)> f2 = [&arr, &vis, &f2, n, m](ll r, ll c) {
        ll ret = 1;
        vis[r][c] = 1;
        for (ll i=0;i<4;i++) {
            ll nr = r + dr[i];
            ll nc = c + dc[i];
            if (nr<0 || nr>=n) continue;
            if (nc<0 || nc>=m) continue;
            if (vis[nr][nc]) continue;
            if (arr[nr][nc] != '#') continue;
            vis[nr][nc] = 1;
            ret += f2(nr, nc);
        }
        return ret;
    };
    bool flag = true;
    bool flag2 = false;
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            if (vis[i][j]) continue;
            if (arr[i][j]=='#') {
                if (flag2) {
                    flag = false;
                    break;
                }
                flag2 = true;
                f2(i, j);
            }
            else {
                if (arr[i][j]=='.') continue;
                if (isdigit(arr[i][j])) {
                    ll cnt = arr[i][j] - '0';
                    ll res = f(i, j);
                    flag = ((res!=-1) && (cnt==res));
                }
                else flag=false;
                if (!flag) break;
            }
        }
        if (!flag) break;
    }
    // for (auto x: vis) cout<<x<<endl;
    ll cnt=0;
    for (i=0;i<n;i++) cnt += accumulate(vis[i].begin(), vis[i].end(), 0LL);
    if (cnt != n*m) flag = false;
    for (i=0;i<n-1;i++)
        for (j=0;j<m-1;j++)
            if (arr[i][j]=='#' && arr[i][j+1]=='#' && arr[i+1][j]=='#' && arr[i+1][j+1]=='#')
                flag=false;
    cout<<(flag ? "YES" : "NO")<<endl;
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

