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

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e18;

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n, m; cin>>n>>m;
    if (n&m&1) {
        cout<<"0\n";
        return;
    }
    vvl arr(n, vl(m));
    vector dp(n, vvl(m, vl(1<<m)));
    function<ll(ll, ll)> f = [&dp, &arr, n, m, &f](ll r, ll c) -> ll {
        if (r==n) return 1;
        if (c==m) return f(r+1, 0);
        ll st = 0;
        for (ll i=0;i<c;i++) {
            st <<= 1;
            if (r+1<n && arr[r+1][i]) st|=1;
        }
        st <<= 1;
        for (ll i=c+1;i<m;i++) {
            st <<= 1;
            if (arr[r][i]) st|=1;
        }
        if (arr[r][c]) return f(r, c+1);
        ll &ret = dp[r][c][st];
        if (ret) return ret;
        if (c+1<m && arr[r][c+1]==0) {
            arr[r][c] = arr[r][c+1] = 1;
            ret += f(r, c+2);
            ret %= 9901;
            arr[r][c] = arr[r][c+1] = 0;
        }
        if (r+1<n) {
            arr[r][c] = arr[r+1][c] = 1;
            ret += f(r, c+1);
            ret %= 9901;
            arr[r][c] = arr[r+1][c] = 0;
        }
        return ret;
    };
    cout<<f(0, 0)<<endl;
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

