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
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

void solve(ll testcase) {
    ll i, j;
    ll n; cin>>n;
    vl in(n), out(n);
    for (i=0;i<n;i++) {
        cin>>in[i]>>out[i];
    }
    vl arr; arr.reserve(2*n);
    arr.insert(arr.end(), in.begin(),  in.end());
    arr.insert(arr.end(), out.begin(), out.end());
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    vl diff(arr.size()+1, 0);
    for (i=0;i<n;i++) {
        ll si = lower_bound(arr.begin(), arr.end(), in[i])  - arr.begin();
        ll ei = lower_bound(arr.begin(), arr.end(), out[i]) - arr.begin();
        diff[si] += 1;
        diff[ei] -= 1;
    }

    ll cur=0, ans=0;
    for (ll k=0;k<arr.size();k++) {
        cur += diff[k];
        if (cur > ans) ans = cur;
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