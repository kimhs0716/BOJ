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

// constexpr ll MOD = 1e9+7;
constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e18;
constexpr ll MAX = 300'001;

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n, t=0;
    while (true) {
        cin>>n;
        if (!n) break;
        vl arr(n); cin>>arr;
        vvl dp(n, vl(n, -1));
        function<ll(ll, ll)> f = [&](ll l, ll r) {
            ll &ret = dp[l][r];
            if (ret==-1) {
                if (l+1==r) {
                    ret = max(arr[l], arr[r]) - min(arr[l], arr[r]);
                }
                else {
                    ll cur = arr[l];
                    if (arr[l+1]<arr[r]) cur += f(l+1, r-1) - arr[r];
                    else cur += f(l+2, r) - arr[l+1];
                    ret = max(ret, cur);
                    cur = arr[r];
                    if (arr[l]<arr[r-1]) cur += f(l, r-2) - arr[r-1];
                    else cur += f(l+1, r-1) - arr[l];
                    ret = max(ret, cur);
                }
            }
            return ret;
        };
        cout<<"In game "<<++t<<", the greedy strategy might lose by as many as "<<f(0, n-1)<<" points.\n";
    }
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

