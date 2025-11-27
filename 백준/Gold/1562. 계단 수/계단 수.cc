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
constexpr ll MOD = 1e9;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e15;

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    vector<vvl> dp(n+1, vvl(1024, vl(10)));
    for (i=1;i<10;i++) {
        dp[1][1<<i][i] = 1;
    }
    for (ll len=2; len<=n; len++) {
        for (ll mask=0; mask<1024; mask++) {
            for (ll u=0; u<10; u++) {
                if (u!=0) dp[len][mask|(1<<(u-1))][u-1] = (dp[len][mask|(1<<(u-1))][u-1] + dp[len-1][mask][u]) % MOD;
                if (u!=9) dp[len][mask|(1<<(u+1))][u+1] = (dp[len][mask|(1<<(u+1))][u+1] + dp[len-1][mask][u]) % MOD;
            }
        }
    }
    ll ans=0;
    for (i=0;i<10;i++)
        ans = (ans+dp[n][1023][i]) % MOD;
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

