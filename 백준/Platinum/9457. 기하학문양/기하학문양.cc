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

ll R[50001], C[50001], a[50001];
void preprocess() {
    ll i, j, k;
    R[1] = 1;
    a[0] = 1;
    a[1] = 2;
    for (i=2;i<=50000;i++) {
        R[i] = ((R[i-1]<<2) - R[i-2] + 10007)%10007;
        a[i] = ((a[i-1]<<2) - a[i-2] + 10007)%10007;
        C[i] = i*(a[i]+10006)%10007;
    }
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    cout<<R[n]<<' ';
    // cout<<a[n]<<' ';
    cout<<C[n]<<endl;;
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    cin >> testcase;
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
    }
}

