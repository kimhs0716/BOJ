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
constexpr ll INF = 1e15;

vl fib;
void preprocess() {
    ll i, j;
    ll a=1, b=1;
    while (b<=30000) {
        fib.push_back(b);
        ll t=a;
        a=b;
        b+=t;
    }
    reverse(fib.begin(), fib.end());
}

void solve(ll tc) {
    ll i, j;
    ll x; cin>>x;
    bitset<22> t;
    for (i=0;i<22;i++) {
        if (fib[i]<=x) {
            x -= fib[i];
            t[i] = 1;
        }
    }
    t <<= 1;
    ll y = 0;
    for (i=0;i<22;i++) {
        if (t[i]) y += fib[i];
    }
    cout<<y<<endl;
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

