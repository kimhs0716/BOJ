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
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) cout<<arr[i]<<' ';
    if (arr.size()) cout<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;
constexpr ll MAX = 1'000'000;

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vl weight(n); cin>>weight;
    ll S = accumulate(weight.begin(), weight.end(), 0LL);
    vl dp(S+1);
    dp[0] = 1;
    for (ll w: weight) {
        for (ll s=S-w;s>=0;s--) {
            dp[s+w] |= (dp[s] << 1);
        }
    }
    // for (i=0;i<=S;i++) {
    //     if (dp[i])
    //         cout<<i<<' '<<dp[i]<<endl;
    // }
    ll min_val=INF, ans=-1;
    for (i=0;i<=S;i++) {
        if ((dp[i]>>(n/2))&1) {
            ll diff = S-2*i;
            if (llabs(diff)<min_val) {
                min_val = llabs(diff);
                ans = i;
            }
        }
    }
    if (2*ans > S) ans = S-ans;
    cout<<ans<<' '<<S-ans<<endl;
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