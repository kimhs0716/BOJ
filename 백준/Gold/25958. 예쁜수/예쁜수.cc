#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

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

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

constexpr ll MAX = 5000;

vl pretty;
void preprocess() {
    ll i, j;
    for (i=1;i<=MAX;i++) {
        ll t=i, s=0;
        while (t) {
            s+=t%10;
            t/=10;
        }
        if (i%s==0) pretty.push_back(i);
    }
}

void solve(ll tc){
    ll i, j;
    ll n, k; cin>>n>>k;
    vvl dp(900, vl(5001));
    for (i=0;i<900;i++) dp[i][0]=1;
    for (i=0;i<pretty.size();i++) {
        for (j=1;j<=5000;j++) {
            for (ll t=j;t>=0;t-=pretty[i]) {
                dp[i+1][j] += dp[i][t];
                dp[i+1][j] %= k;
            }
        }
    }
    cout<<dp[899][n]<<endl;
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