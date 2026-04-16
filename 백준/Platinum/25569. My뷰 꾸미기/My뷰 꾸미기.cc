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
    freopen("boj.in", "r", stdin);
    freopen("boj.out", "w", stdout);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

ll __pow(ll a, ll b) {
    ll ret=1;
    while (b) {
        if (b&1) ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}

ll __inv(ll n) {
    return __pow(n, MOD-2);
}

constexpr ll MAX = 600000;
ll fac[MAX+1], inv_fac[MAX+1];
void preprocess() {
    ll i, j, k;
    fac[0]=1;
    for (i=1;i<=MAX;i++) fac[i] = fac[i-1] * i % MOD;
    inv_fac[MAX] = __inv(fac[MAX]);
    for (i=MAX-1;i>=1;i--) {
        inv_fac[i] = inv_fac[i+1] * (i+1) % MOD;
    }
    inv_fac[0]=1;
}

ll comb(ll a, ll b) {
    return (fac[a]*inv_fac[b]%MOD)*inv_fac[a-b]%MOD;
}

void solve(ll tc) {
    ll i, j, k;
    ll ans=1;
    ll n; cin>>n;
    while (n--) {
        ll a, b; cin>>a>>b;
        if (a>b) swap(a, b);
        ans=ans*(comb(a+b, a)-1+MOD)%MOD;
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