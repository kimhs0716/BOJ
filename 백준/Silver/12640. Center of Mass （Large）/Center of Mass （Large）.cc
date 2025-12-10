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

void preprocess() {
    ll i, j;
}

ld dist(array<ld, 3> arr) {
    auto [x, y, z] = arr;
    return x*x + y*y + z*z;
}

ld f(array<ld, 6> arr, ld t) {
    auto [x, y, z, a, b, c] = arr;
    return dist({x+t*a, y+t*b, z+t*c});
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    array<ld, 6> arr {};
    ll vx=0, vy=0, vz=0;
    for (j=0;j<n;j++) {
        array<ll, 6> t;
        for (auto &x: t) cin>>x;
        for (i=0;i<6;i++) arr[i] += t[i];
        vx += t[3];
        vy += t[4];
        vz += t[5];
    }
    for (i=0;i<6;i++) arr[i] /= n;
    if (vx==0 && vy==0 && vz==0) {
        cout<<"Case #"<<tc<<": ";
        cout<<fixed<<setprecision(10);
        cout<<sqrtl(f(arr, 0))<<' '<<0<<endl;
        return;
    }
    ld lo=0, hi=1e30;
    ld diff = 1e-12;
    while (lo+diff < hi) {
        ld m1 = (2*lo+hi)/3;
        ld m2 = (lo+2*hi)/3;
        ld f1 = f(arr, m1), f2 = f(arr, m2);
        if (f1+diff < f2) hi = m2;
        else lo = m1;
    }
    cout<<"Case #"<<tc<<": ";
    cout<<fixed<<setprecision(10);
    cout<<sqrtl(f(arr, lo))<<' '<<lo<<endl;
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

