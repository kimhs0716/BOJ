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

ll count(vl &arr, ll x) {
    return lower_bound(arr.begin(), arr.end(), x+1) - arr.begin();
}

void solve(ll testcase) {
    ll i, j, k;
    ll n, m; cin>>n>>m;
    vvl arr(n, vl(m));
    for (i=0;i<n;i++) {
        string s; cin>>s;
        for (j=0;j<m;j++) arr[i][j] = s[j]=='1';
    }
    vvl prefix(n, vl(m+1));
    for (i=0;i<n;i++) {
        for (j=1;j<=m;j++) prefix[i][j] = prefix[i][j-1] + (!arr[i][j-1]);
    }

    // for (i=0;i<n;i++) {
    //     for (j=0;j<=m;j++) cout<<prefix[i][j]<<' ';
    //     cout<<endl;
    // }

    ll ans=0;
    for (i=0;i<m;i++) {
        for (j=i;j<m;j++) {
            ll cur_max=0;
            ll cur=0;
            for (k=0;k<n;k++) {
                if (prefix[k][j+1]-prefix[k][i] != j-i+1) {
                    cur = 0;
                }
                else cur++;
                cur_max = max(cur, cur_max);
            }
            ans = max(ans, cur_max * (j-i+1));
        }
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