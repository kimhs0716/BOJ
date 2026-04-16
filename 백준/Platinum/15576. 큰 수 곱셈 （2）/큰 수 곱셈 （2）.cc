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

ll modmul(ll a, ll b, ll m) {
    return ll((__int128)a*(__int128)b%m);
}

ll modpow(ll n, ll k, ll m) {
    ll ret=1;
    n%=m;
    while (k) {
        if (k&1) ret=modmul(ret, n, m);
        n=modmul(n, n, m);
        k>>=1;
    }
    return ret;
}

// Usage: vl conv = multiply(a, b, mod, w);
// O(n*logn)
// Note: a, b는 ref가 아니라 복사
// Note: (mod, w) : (998 244 353, 3) or (985 661 441, 3) or (1 012 924 417, 5)
void ntt(vl &f, ll mod, ll w, bool inv=false) {
    ll n=f.size(), j=0;
    vl root(n>>1);
    for (ll i=1;i<n;i++) {
        ll bit=n>>1;
        while (j>=bit) {
            j-=bit;
            bit>>=1;
        }
        j+=bit;
        if (i<j) swap(f[i], f[j]);
    }
    ll ang = modpow(w, (mod-1)/n, mod);
    if (inv) ang=modpow(ang, mod-2, mod);
    root[0]=1;
    for (ll i=1;i<(n>>1);i++)
        root[i]=root[i-1]*ang%mod;
    for (ll len=2;len<=n;len<<=1) {
        ll step=n/len;
        for (ll i=0;i<n;i+=len) {
            for (ll k=0;k<(len>>1);k++) {
                ll u=f[i+k];
                ll v=f[i+k+(len>>1)]*root[step*k]%mod;
                f[i+k]=(u+v)%mod;
                f[i+k+(len>>1)]=(u-v)%mod;
                if (f[i+k+(len>>1)]<0)
                    f[i+k+(len>>1)]+=mod;
            }
        }
    }
    if (inv) {
        ll inv_n=modpow(n, mod-2, mod);
        for (ll i=0;i<n;i++)
            f[i]=f[i]*inv_n%mod;
    }
}

vl multiply(vl a, vl b, ll mod, ll w) {
    ll n=2;
    while (n<(ll)a.size()+(ll)b.size()) n<<=1;
    a.resize(n);
    b.resize(n);
    ntt(a, mod, w);
    ntt(b, mod, w);
    for (ll i=0;i<n;i++)
        a[i]=a[i]*b[i]%mod;
    ntt(a, mod, w, true);
    return a;
}

void solve(ll testcase) {
    ll i, j;
    string sa, sb; cin>>sa>>sb;
    reverse(sa.begin(), sa.end());
    reverse(sb.begin(), sb.end());
    ll na=sa.size(), nb=sb.size();
    vl a(na), b(nb);
    for (i=0;i<na;i++) a[i]=sa[i]-'0';
    for (i=0;i<nb;i++) b[i]=sb[i]-'0';
    vl c = multiply(a, b, 998'244'353, 3);
    for (i=0;i<c.size();i++) {
        if (c[i]>=10) {
            if (i==c.size()-1) c.push_back(0);
            c[i+1] += c[i]/10;
            c[i] %= 10;
        }
    }
    while (c.size()>=2 && c.back()==0) c.pop_back();
    reverse(c.begin(), c.end());
    for (auto x: c) cout<<x;
    cout<<endl;
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