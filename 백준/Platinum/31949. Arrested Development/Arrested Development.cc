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

constexpr ll MAX = 5000000;
void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vl dp(MAX+1, -1);
    dp[0] = 0;
    for (i=0;i<n;i++) {
        ll a, b; cin>>a>>b;
        for (j=MAX;j>=0;j--) {
            if (dp[j]!=-1) dp[j] += b;
            if (j-a>=0 && dp[j-a]!=-1 && (dp[j]==-1 || dp[j-a]<dp[j])) dp[j]=dp[j-a];
        }
    }
    // for (i=0;i<=20;i++)
    //     cout<<i<<": "<<dp[i]<<endl;
    ll ans=INF;
    for (i=0;i<=MAX;i++) {
        if (dp[i]!=-1) ans = min(ans, max(i, dp[i]));
    }
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