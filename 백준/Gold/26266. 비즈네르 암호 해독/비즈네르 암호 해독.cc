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
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;

}

bool check(vl &arr, ll cnt) {
    ll n=arr.size();
    for (ll s=cnt;s<n;s+=cnt) {
        for (ll i=0;i<cnt;i++) {
            if (arr[s+i] != arr[i]) return false;
        }
    }
    return true;
}

void solve(ll testcase) {
    ll i, j, k;
    string s, t; cin>>s>>t;
    ll n=s.size();
    vl arr(n);
    for (i=0;i<n;i++) {
        arr[i] = (t[i]-s[i]+26)%26;
    }
    for (i=1;i<=n;i++) {
        if (n%i) continue;
        if (check(arr, i)) {
            for (j=0;j<i;j++) cout<<(char)((arr[j]+25)%26+'A');
            return;
        }
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