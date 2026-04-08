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
constexpr ll INF = 1e18;
constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll n, m; cin>>n>>m;
    vl s(n), t(m); cin>>s>>t;
    vl lcs(m+1), cnt(m+1);
    vl plcs(m+1), pcnt(m+1);
    for (i=0;i<=m;i++) pcnt[i] = 1;
    for (i=1;i<=n;i++) {
        cnt[0] = 1;
        lcs[0] = 0;
        for (j=1;j<=m;j++) {
            if (s[i-1]==t[j-1]) {
                lcs[j] = plcs[j-1]+1;
                cnt[j] = pcnt[j-1];
            }
            else {
                if (plcs[j] == lcs[j-1]) {
                    lcs[j] = plcs[j];
                    cnt[j] = (pcnt[j] + cnt[j-1]) % MOD;
                    if (lcs[j] == plcs[j-1])
                        cnt[j] += MOD - pcnt[j-1];
                    cnt[j] %= MOD;
                }
                else if (plcs[j] < lcs[j-1]) {
                    lcs[j] = lcs[j-1];
                    cnt[j] = cnt[j-1];
                }
                else {
                    lcs[j] = plcs[j];
                    cnt[j] = pcnt[j];
                }
            }
        }
        swap(lcs, plcs);
        swap(cnt, pcnt);
    }
    // for (i=0;i<=n;i++) {
    //     for (j=0;j<=m;j++) {
    //         cout<<lcs[i][j]<<'|'<<cnt[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    cout<<pcnt[m]<<endl;
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
