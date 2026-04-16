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
ostream& operator<<(ostream &os, vector<T> &arr) {
    if (arr.size()==0) return os<<"()";
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) os<<arr[i]<<' ';
    if (arr.size()) os<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;
// constexpr ll MAX = 65536;

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    vvl arr(8, vl(7)), vis(8, vl(7));
    for (i=0;i<8;i++) {
        string s; cin>>s;
        for (j=0;j<7;j++) arr[i][j]=s[j]-'0';
    }
    vl used(49);
    function<ll(ll, ll)> backtrack = [&arr, &used, &vis, &backtrack](ll r, ll c) -> ll {
        if (r==8) return 1;
        if (c==7) return backtrack(r+1, 0);
        if (vis[r][c]) return backtrack(r, c+1);
        // cout<<r<<' '<<c<<endl;
        ll ret=0;
        if (c<6 && vis[r][c+1]==0) {
            ll a=arr[r][c], b=arr[r][c+1];
            if (a>b) swap(a, b);
            if (used[a*7+b]==0) {
                vis[r][c]=vis[r][c+1]=1;
                used[a*7+b]=1;
                ret += backtrack(r, c+1);
                used[a*7+b]=0;
            }
            vis[r][c]=vis[r][c+1]=0;
        }
        if (r<7) {
            ll a=arr[r][c], b=arr[r+1][c];
            vis[r][c]=vis[r+1][c]=1;
            if (a>b) swap(a, b);
            if (used[a*7+b]==0) {
                vis[r][c]=vis[r+1][c]=1;
                used[a*7+b]=1;
                ret += backtrack(r, c+1);
                used[a*7+b]=0;
            }
            vis[r][c]=vis[r+1][c]=0;
        }
        return ret;
    };
    cout<<backtrack(0, 0)<<endl;
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