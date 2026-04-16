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

// constexpr ll MOD = 1e9+7;
constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e18;
constexpr ll MAX = 300'001;

vl manacher(string &s) {
    ll n = s.size();
    vl a(n);
    ll p=0, r=0;
    for (ll i=0;i<n;i++) {
        if (i<=r) a[i] = min(a[p-(i-p)], r-i);
        ll c = a[i];
        while (i-c-1>=0 && i+c+1<n && s[i-c-1]==s[i+c+1]) c++;
        a[i] = c;
        if (r<i+c) {
            r = i+c;
            p = i;
        }
    }
    return a;
}

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    string t, s; cin>>t;
    for (auto ch: t) {
        s.push_back('|');
        s.push_back(ch);
    }
    s.push_back('|');
    // cout<<s<<endl;
    vl res = manacher(s);
    // cout<<res<<endl;
    ll ans = 0;
    for (auto x: res) ans += (x+1)/2;
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

