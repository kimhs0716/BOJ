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

vl get_pi(vl &p) {
    ll n = p.size();
    vl pi(n);
    ll j=0;
    for (ll i=1;i<n;i++) {
        while (j && p[i]!=p[j]) j = pi[j-1];
        if (p[i]==p[j]) pi[i] = ++j;
    }
    return pi;
}

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    vl pi = get_pi(arr);
    // cout<<pi<<endl;
    ll p = n - pi.back();
    // cout<<p<<endl;
    ll a, b; cin>>a>>b;
    ll d = (b-a)/p;
    a = (a%p+p)%p;
    b = (b%p+p)%p;
    if (a>b) b += p;
    // cout<<a<<' '<<b<<' '<<d<<endl;
    ll s = accumulate(arr.begin(), arr.begin()+p, 0LL);
    ll ans = s * d;
    for (i=a;i<b;i++) ans += arr[i%p];
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
