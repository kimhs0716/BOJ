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
constexpr ll INF = 1e15;

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    vector<string> arr(n); cin>>arr;
    ll r = -1, c = -1;
    for (i=0;i<n;i++) {
        ll cnt = 0;
        for (j=0;j<n;j++) {
            if (arr[i][j]=='*') cnt++;
        }
        if (cnt>=3) break;
    }
    r = i;
    for (i=0;i<n;i++) {
        if (arr[r-1][i]=='*') break;
    }
    c = i;
    cout<<r+1<<' '<<c+1<<endl;
    ll cnt = 0;
    for (i=c-1;i>=0;i--) {
        if (arr[r][i]!='*') break;
        cnt++;
    }
    cout<<cnt<<' ';
    cnt = 0;
    for (i=c+1;i<n;i++) {
        if (arr[r][i]!='*') break;
        cnt++;
    }
    cout<<cnt<<' ';
    cnt = 0;
    for (i=r+1;i<n;i++) {
        if (arr[i][c]!='*') break;
        cnt++;
    }
    cout<<cnt<<' ';
    ll t = i;
    cnt = 0;
    for (i=t;i<n;i++) {
        if (arr[i][c-1]!='*') break;
        cnt++;
    }
    cout<<cnt<<' ';
    cnt = 0;
    for (i=t;i<n;i++) {
        if (arr[i][c+1]!='*') break;
        cnt++;
    }
    cout<<cnt<<endl;
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
