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

template <typename T>
ostream& operator<<(ostream &os, vector<T> &arr) {
    for (auto &x: arr) os<<x<<' ';
    return os;
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

constexpr ll MAX = 100000;
void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    vvl dp(n, vl(MAX+1));
    for (i=0;i<=MAX;i++) {
        dp[0][i] = i;
    }
    for (i=1;i<n;i++) {
        for (j=0;j<arr[i];j++) {
            dp[i][j] = dp[i-1][j];
            for (k=j+arr[i];k<=MAX;k+=arr[i])
                dp[i][k] = min(dp[i][k-arr[i]]+1, dp[i-1][k]);
        }
    }
    auto greedy = [&arr, &n](ll x) {
        ll ret=0;
        for (ll i=n-1;i>=0;i--) {
            ret+=x/arr[i];
            x%=arr[i];
            if (!x) break;
        }
        return ret;
    };
    // for (i=0;i<n;i++) {
    //     for (j=0;j<10;j++) cout<<dp[i][j]<<' ';
    //     cout<<endl;
    // }
    // for (i=0;i<10;i++) cout<<greedy(i)<<' ';
    // cout<<endl;
    for (i=1;i<=MAX;i++) {
        if (greedy(i) != dp[n-1][i]) {
            cout<<i<<endl;
            return;
        }
    }
    cout<<"-1\n";
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