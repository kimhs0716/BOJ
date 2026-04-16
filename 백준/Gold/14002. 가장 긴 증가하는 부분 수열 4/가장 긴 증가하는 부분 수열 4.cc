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
    for (auto &x: arr) os<<x<<' ';
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
    vl arr(n); cin>>arr;
    vl dp(n, 1), prev(n, -1);
    ll ans=1, idx=0;
    for (i=1;i<n;i++) {
        for (j=0;j<i;j++) {
            if (arr[i]>arr[j] && dp[i]<dp[j]+1) {
                dp[i]=dp[j]+1;
                prev[i]=j;
            }
        }
        if (dp[i] >= ans) {
            ans=dp[i];
            idx=i;
        }
    }
    cout<<ans<<endl;
    vl st;
    while (ans--) {
        st.push_back(arr[idx]);
        idx = prev[idx];
    }
    reverse(st.begin(), st.end());
    for (auto x: st) cout<<x<<' ';
    cout<<endl;
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