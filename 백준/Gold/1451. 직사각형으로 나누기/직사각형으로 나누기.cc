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

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e18;
constexpr ll MAX = 100'000;

void preprocess() {
    ll i, j, k;
}

ll check(vvl &arr) {
    ll i, j, k;
    ll r=arr.size(), c=arr[0].size();
    ll ret=0;
    ll sum=0;
    for (i=0;i<r;i++)
        for (j=0;j<c;j++)
            sum += arr[i][j];
    for (i=0;i<c;i++) {
        ll sumi = 0;
        for (ll rr=0;rr<r;rr++)
            for (ll cc=0; cc<=i; cc++) sumi += arr[rr][cc];
        for (j=i+1;j<c-1;j++) {
            ll sumj = 0;
            for (ll rr=0;rr<r;rr++)
                for (ll cc=i+1; cc<=j; cc++) sumj += arr[rr][cc];
            ll sumk = sum-(sumi+sumj);
            // cout<<sumi<<' '<<sumj<<' '<<sumk<<endl;
            ret = max(ret, sumi*sumj*sumk);
        }
    }
    for (i=0;i<r-1;i++) {
        for (j=0;j<c-1;j++) {
            ll sumi=0, sumj=0;
            for (ll rr=0; rr<=i; rr++)
                for (ll cc=0; cc<=j; cc++)
                    sumi += arr[rr][cc];
            for (ll rr=i+1; rr<r; rr++)
                for (ll cc=0; cc<=j; cc++)
                    sumj += arr[rr][cc];
            ll sumk = sum-(sumi+sumj);
            ret = max(ret, sumi*sumj*sumk);
        }
    }
    return ret;
}

void rotate(vvl &arr) {
    ll r=arr.size(), c=arr[0].size();
    vvl ret(c, vl(r));
    for (ll i=0;i<r;i++) {
        for (ll j=0;j<c;j++)
            ret[c-j-1][i] = arr[i][j];
    }
    swap(ret, arr);
}

void solve(ll testcase) {
    ll i, j, k;
    ll r, c; cin>>r>>c;
    vvl arr(r, vl(c));
    for (i=0;i<r;i++) {
        string s; cin>>s;
        for (j=0;j<c;j++) arr[i][j] = s[j] - '0';
    }
    ll ans=0;
    for (i=0;i<4;i++) {
        ans = max(ans, check(arr));
        rotate(arr);
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

