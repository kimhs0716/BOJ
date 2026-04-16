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

ll modpow(ll n, ll k, ll m) {
    ll ret=1;
    n%=m;
    while (k) {
        if (k&1) ret=ret*n%m;
        n=n*n%m;
        k>>=1;
    }
    return ret;
}

// Usage: vl conv = multiply(a, b, mod, w);
// O(n*logn)
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

vl multiply(vl &_a, vl &_b, ll mod, ll w) {
    vl a=_a, b=_b;
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


void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j, k;
    ll mod=998'244'353, w=3;
    vl a, b;
    string s;
    cin>>s;
    for (auto ch: s) a.push_back(ch-'0');
    cin>>s;
    for (auto ch: s) b.push_back(ch-'0');
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vl c = multiply(a, b, mod, w);
    // for (auto x: c) cout<<x<<' '; cout<<endl;
    string ans;
    ll carry=0;
    for (auto it=c.begin();it!=c.end();it++) {
        carry += *it;
        ans.push_back(carry%10+'0');
        carry/=10;
    }
    while (ans.back()=='0') ans.pop_back();
    if (ans.empty()) ans="0";
    reverse(ans.begin(), ans.end());
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