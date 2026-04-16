#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

#define endl '\n'
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;

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

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

// OR-transform
vl fwt_or(vl &x, bool inv) {
    vl a=x;
    ll n=a.size();
    ll dir=inv?-1:1;
    for (ll s=2,h=1;s<=n;s<<=1,h<<=1) {
        for (ll l=0;l<n;l+=s) {
            for (ll i=0;i<h;i++) {
                a[l+h+i]+=dir*a[l+i];
            }
        }
    }
    return a;
}

// AND-transform
vl fwt_and(vl& x, bool inv) {
    vl a=x;
    ll n=a.size();
    ll dir=inv?-1:1;
    for (ll s=2,h=1;s<=n;s<<=1,h<<=1) {
        for (ll l=0;l<n;l+=s) {
            for (ll i=0;i<h;i++) {
                a[l+i]+=dir*a[l+h+i];
            }
        }
    }
    return a;
}

// XOR-transform
vl fwt_xor(vl& x, bool inv) {
    vl a=x;
    ll n=a.size();
    for (ll s=2,h=1;s<=n;s<<=1,h<<=1) {
        for (ll l=0;l<n;l+=s) {
            for (ll i=0;i<h;i++) {
                ll t=a[l+h+i];
                a[l+h+i]=a[l+i]-t;
                a[l+i]+=t;
                if (inv) {
                    a[l+i]/=2;
                    a[l+h+i]/=2;
                }
            }
        }
    }
    return a;
}

vl multiply(vl a, vl b) {
    ll n = 1;
    while (n < max(a.size(), b.size())) n<<= 1;
    a.resize(n);
    b.resize(n);
    a = fwt_or(a, false);
    b = fwt_or(b, false);
    vl c(n);
    for (ll i=0;i<n;i++) c[i]=a[i]*b[i];
    return fwt_or(c, true);
}

vl multiply_or(vl a, vl b) {
    ll n = 1;
    while (n < max(a.size(), b.size())) n<<= 1;
    a.resize(n);
    b.resize(n);
    a = fwt_or(a, false);
    b = fwt_or(b, false);
    vl c(n);
    for (ll i=0;i<n;i++) c[i]=a[i]*b[i];
    return fwt_or(c, true);
}

vl multiply_and(vl a, vl b) {
    ll n = 1;
    while (n < max(a.size(), b.size())) n<<= 1;
    a.resize(n);
    b.resize(n);
    a = fwt_and(a, false);
    b = fwt_and(b, false);
    vl c(n);
    for (ll i=0;i<n;i++) c[i]=a[i]*b[i];
    return fwt_and(c, true);
}

vl multiply_xor(vl a, vl b) {
    ll n = 1;
    while (n < max(a.size(), b.size())) n<<= 1;
    a.resize(n);
    b.resize(n);
    a = fwt_xor(a, false);
    b = fwt_xor(b, false);
    vl c(n);
    for (ll i=0;i<n;i++) c[i]=a[i]*b[i];
    return fwt_xor(c, true);
}


void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    constexpr ll MAXN = 1e6;
    vl a(MAXN+1);
    ll n, k; cin>>n>>k;
    for (i=0;i<n;i++) {
        ll x; cin>>x;
        a[x]++;
    }
    vl b=a;
    vl mult_or = multiply_or(a, b);
    vl mult_and = multiply_and(a, b);
    vl mult_xor = multiply_xor(a, b);
    if (k==0) {
        mult_xor[0] -= n;
    }
    cout<<(mult_and[k]-a[k])/2<<endl;
    cout<<(mult_or[k]-a[k])/2<<endl;
    cout<<mult_xor[k]/2<<endl;
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