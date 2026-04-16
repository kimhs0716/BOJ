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

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

vvl comb(101, vl(101));
void preprocess() {
    ll i, j;
    for (i=0;i<101;i++) comb[i][0]=comb[i][i]=1;
    for (i=1;i<101;i++)
        for (j=1;j<i;j++)
            comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%MOD;
    // for (i=0;i<10;i++) {
    //     for (j=0;j<10;j++)
    //         cout<<comb[i][j]<<' ';
    //     cout<<endl;
    // }
}

void solve(ll tc){
    ll i, j;
    ll m, n; cin>>m>>n;
    ll ans=modpow(m, n, MOD);
    for (i=1;i<m;i++) {
        if (i&1) ans -= comb[m][i]*modpow(m-i, n, MOD)%MOD;
        else ans += comb[m][i]*modpow(m-i, n, MOD)%MOD;
        if (ans<0) ans+=MOD;
        else ans %= MOD;
    }
    cout<<"Case #"<<tc<<": ";
    cout<<ans<<endl;
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