#include <bits/stdc++.h>
// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target ("avx,avx2,fma")

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
    ll r, c; cin>>r>>c;
    vector arr(r, vector<array<bool, 4>>(c));
    for (i=0;i<r;i++) {
        string s; cin>>s;
        for (j=0;j<c;j++) {
            if (s[j]=='A') arr[i][j] = {0, 0, 0, 0};
            if (s[j]=='B') arr[i][j] = {0, 1, 0, 1};
            if (s[j]=='C') arr[i][j] = {1, 1, 0, 0};
            if (s[j]=='D') arr[i][j] = {1, 0, 1, 0};
            if (s[j]=='E') arr[i][j] = {0, 0, 1, 1};
            if (s[j]=='F') arr[i][j] = {1, 1, 1, 1};
        }
    }
    vvl vis(r, vl(c));
    function<void(ll, ll)> dfs = [&arr, &r, &c, &vis, &dfs](ll rr, ll cc) -> void {
        vis[rr][cc]=1;
        if (rr<r-1 && arr[rr][cc][3] && arr[rr+1][cc][0] && !vis[rr+1][cc]) {
            dfs(rr+1, cc);
        }
        if (rr>0 && arr[rr][cc][0] && arr[rr-1][cc][3] && !vis[rr-1][cc]) {
            dfs(rr-1, cc);
        }
        if (cc<c-1 && arr[rr][cc][2] && arr[rr][cc+1][1] && !vis[rr][cc+1]) {
            dfs(rr, cc+1);
        }
        if (cc>0 && arr[rr][cc][1] && arr[rr][cc-1][2] && !vis[rr][cc-1]) {
            dfs(rr, cc-1);
        }
    };
    ll ans=0;
    for (i=0;i<r;i++) {
        for (j=0;j<c;j++) {
            if (vis[i][j] || arr[i][j]==array<bool, 4>({0, 0, 0, 0})) continue;
            ans++;
            dfs(i, j);
        }
    }
    cout<<ans<<endl;
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