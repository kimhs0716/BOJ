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

ll large_mod_mul(ll a, ll b, ll m) {
    return ll((__int128)a*(__int128)b%m);
}

bool is_prime(ll n) {
    if (n<2 || n%2==0 || n%3==0) return n==2 || n==3;
    ll k=__builtin_ctzll(n-1), d=n-1>>k;
    for (ll a: { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 }) {
        ll p=modpow(a%n, d, n), i=k;
        while (p!=1 && p!=n-1 && a%n && i--) p = large_mod_mul(p, p, n);
        if (p!=n-1 && i!=k) return 0;
    }
    return 1;
}

ll pollard(ll n) {
    auto f=[n](ll x) { return (large_mod_mul(x, x, n)+3)%n; };
    ll x=0, y=0, t=30, p=2, i=1, q;
    while (t++ % 40 || gcd(p, n)==1) {
        if (x==y) x=++i, y=f(x);
        if (q=large_mod_mul(p, abs(x-y), n)) p=q;
        x=f(x), y=f(f(y));
    }
    return gcd(p, n);
}
void factor(ll n, vl &ret) {
    if (n==1) return;
    if (is_prime(n)) {
        ret.push_back(n);
        return;
    }
    ll d=pollard(n);
    factor(d, ret);
    factor(n/d, ret);
}

pll extended_gcd(ll a, ll b){if(b == 0)return {1, 0};auto t = extended_gcd(b, a % b);return {t.second, t.first - t.second * (a / b)};}
ll modinverse(ll a, ll m){return (extended_gcd(a, m).first % m + m) % m;}

ll chinese_remainder(vl &a, vl &n, ll s=0) {
    ll size=a.size();
    if (s==size-1) return a[s];
    ll tmp=modinverse(n[s], n[s+1]);
    ll tmp2=(tmp*(a[s+1]-a[s])%n[s+1]+n[s+1])%n[s+1];
    ll ora=a[s+1];
    ll tgcd=gcd(n[s],n[s+1]);
    if ((a[s+1]-a[s])%tgcd!=0) return -1;
    a[s+1]=a[s]+n[s]/tgcd*tmp2;
    n[s+1]*=n[s]/tgcd;
    ll ret=chinese_remainder(a, n, s+1);
    n[s+1]/=n[s]/tgcd;
    a[s+1]=ora;
    return ret;
}

// Usage: vector<pll> qs(q); vl ans = sol(q, qs, mod);
// O(mod^0.25 + sum(p^e) + q*sum(log_p n) + qk), k = mod의 소인수 개수
// Note: qs[i] = {n, r}, nCr mod p^e in O(p^e)
auto sol_p_e = [](ll q, vector<pll> &qs, ll p, ll e, ll mod) {
    vl dp(mod, 1);
    for (ll i=0;i<mod;i++) {
        if (i) dp[i]=dp[i - 1];
        if (i%p==0) continue;
        dp[i]=large_mod_mul(dp[i], i, mod);
    }
    auto f=[&](ll n) {
        ll res=0;
        while (n/=p) res+=n;
        return res;
    };
    auto g = [&](ll n) {
        auto rec=[&](auto &self, ll n) -> ll {
            if (n==0) return 1;
            ll q=n/mod, r=n%mod;
            ll ret=large_mod_mul(self(self, n/p), dp[r], mod);
            if (q&1) ret=large_mod_mul(ret, dp[mod-1], mod);
            return ret;
        };
        return rec(rec, n);
    };
    auto bino = [&](ll n, ll r) -> ll {
        if (n<r) return 0;
        if (r==0 || r==n) return 1;
        ll a=f(n)-f(r)-f(n-r);
        if (a>=e) return 0;
        ll b=large_mod_mul(g(n), modinverse(large_mod_mul(g(r), g(n-r), mod), mod), mod);
        return large_mod_mul(modpow(p, a, mod), b, mod);
    };
    vl res(q, 0);
    for (ll i=0;i<q;i++) {
        auto [n, r]=qs[i];
        res[i]=bino(n, r);
    }
    return res;
};

auto sol = [](ll q, auto &qs, ll mod) {
    vl f;
    factor(mod, f);
    sort(f.begin(), f.end());
    vector<pll> fac;
    for (auto ff: f) {
        if (fac.empty() || fac.back().first!=ff)
            fac.push_back({ff, 0});
        fac.back().second++;
    }
    vvl r(q, vl(fac.size(), 0));
    vl m(fac.size(), 1);
    for (ll i=0;i<fac.size();i++) {
        auto [p, e]=fac[i];
        for (ll j=0;j<e;j++) m[i]*=p;
        auto res=sol_p_e(q, qs, p, e, m[i]);
        for (ll j=0;j<q;j++) r[j][i]=res[j];
    }
    vl res(q, 0);
    for (ll i=0;i<q;i++) {
        res[i]=chinese_remainder(r[i], m);
    }
    return res;
};



void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j, k;
    ll n, r, m; cin>>n>>r>>m;
    vector<pll> qs(1, {n, r});
    auto ans=sol(1, qs, m);
    cout<<ans[0]<<endl;
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