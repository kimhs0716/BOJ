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
    array<vl, 4> arr;
    for (i=0;i<n;i++) {
        ll x; cin>>x;
        if (x>0) arr[0].push_back(x);
        else arr[1].push_back(-x);
    }
    for (i=0;i<n;i++) {
        ll x; cin>>x;
        if (x>0) arr[2].push_back(x);
        else arr[3].push_back(-x);
    }
    for (auto &x: arr) sort(x.begin(), x.end());
    ll ans = 0;
    ll m;
    n=arr[0].size(), m=arr[3].size();
    i=0, j=0;
    while (i<n && j<m) {
        if (arr[0][i] < arr[3][j]) {
            ans++;
            i++;
            j++;
        }
        else j++;
    }
    n=arr[2].size(), m=arr[1].size();
    i=0, j=0;
    while (i<n && j<m) {
        if (arr[2][i] < arr[1][j]) {
            ans++;
            i++;
            j++;
        }
        else j++;
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
