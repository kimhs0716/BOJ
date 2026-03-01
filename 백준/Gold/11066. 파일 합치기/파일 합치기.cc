#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

#define endl '\n'
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;

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

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll modpow(ll a, ll b, ll rem){ll p=1;a%=rem;for(;b;b>>=1,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
pll extended_gcd(ll a, ll b) {
    if (b==0) return {1, 0};
    auto t=extended_gcd(b, a%b);
    return {t.second, t.first-t.second*(a/b)};
}
ll modinverse(ll a, ll m) {
    return (extended_gcd(a, m).first%m+m)%m;
}

void preprocess() {
    ll i, j;
}

// Note: O(n^3) -> O(n^2), 아래 3가지 조건 만족
// D[i][j] = min{i<k<j}(D[i][k]+D[k][j]) + C[i][j]
// C[a][c]+C[b][d] <= C[a][d]+C[b][c], (a<=b<=c<=d)
// C[b][c] <= C[a][d]
// Usage: vvl dp = knuth(arr);
vvl knuth(vl &arr) {
    constexpr ll INF = 2e18;
    ll i, k;
    ll n=arr.size();
    vl s(n+1); // 누적 합 배열
    for (i=0;i<n;i++) s[i+1]=s[i]+arr[i];

    vvl dp(n+1, vl(n+1)), opt(n+1, vl(n+1));
    for (i=1;i<=n;i++) {
        dp[i-1][i]=0;
        opt[i-1][i]=i;
    }

    for (i=2;i<=n;i++) {
        for (ll l=0;i+l<=n;l++) {
            ll r=i+l;
            dp[l][r]=INF;
            ll start=opt[l][r-1];
            ll end=opt[l+1][r];
            for (k=start;k<=end;k++) {
                ll cost=dp[l][k]+dp[k][r]+s[r]-s[l];
                if (cost<dp[l][r]) {
                    dp[l][r]=cost;
                    opt[l][r]=k;
                }
            }
        }
    }

    return dp;
}


void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    vvl dp = knuth(arr);
    cout<<dp[0][n]<<endl;
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