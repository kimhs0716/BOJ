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

ll check(vl &arr, ll p, ll q, ll r, ll k) {
    ll ret = 0;
    for (auto x: arr) {
        if (x>k+r) ret += x-p;
        else if (x<k) ret += x+q;
        else ret += x;
    }
    return ret;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    ll p, q, r, s; cin>>p>>q>>r>>s;
    ll lo=0, hi=1e10;
    if (check(arr, p, q, r, hi)<s) {
        cout<<"-1\n";
        return;
    }
    while (lo+1<hi) {
        ll mid=lo+hi>>1;
        if (check(arr, p, q, r, mid)<s) lo=mid;
        else hi=mid;
    }
    cout<<hi<<endl;
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
