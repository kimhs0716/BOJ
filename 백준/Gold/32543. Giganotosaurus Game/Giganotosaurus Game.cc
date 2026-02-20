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
constexpr ll INF = (ll)1e18+1;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    vl arr(n);
    string s; cin>>s;
    for (i=0;i<n;i++) {
        arr[i] = s[i]=='#';
    }
    ll k = sqrtl(n<<1)+1;
    vvl dp(k+1, vl(n));
    dp[0][0] = 1;
    ll ans = 0;
    for (i=0;i<=k;i++) {
        for (j=0;j<n;j++) {
            if (j+1>=n || arr[j+1]==0) {
                if (j+1<n) dp[i][j+1] = (dp[i][j+1]+dp[i][j])%MOD;
                else ans = (ans+dp[i][j]) % MOD;
            }
            if (i+1<=k && (j+i+2>=n || arr[j+i+2]==0)) {
                if (j+i+2<n) dp[i+1][j+i+2] = (dp[i+1][j+i+2]+dp[i][j])%MOD;
                else ans = (ans+dp[i][j])%MOD;
            }
        }
    }
    cout<<ans<<endl;
    // for (auto &x: dp) {
    //     for (auto y: x) cout<<y<<' ';
    //     cout<<endl;
    // }
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
