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

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    vvl arr(n, vl(n)); cin>>arr;
    vvl dp(n, vl(n));
    for (i=0;i<n;i++) for (j=i;j<n;j++)
        dp[i][j] = arr[i][j];
    for (ll len=2;len<=n;len++) {
        for (ll l=0;l+len<=n;l++) {
            ll r = l+len-1;
            ll &temp = dp[l][r] = dp[l+1][r];
            for (i=l+1;i<=r;i++) {
                ll left = (i==l+1 ? 0 : dp[l+1][i-1]);
                ll right = (i==r ? 0 : dp[i+1][r]);
                temp = max(temp, arr[l][i] + left + right);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    // for (auto &x : dp) cout<<x<<endl;
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
