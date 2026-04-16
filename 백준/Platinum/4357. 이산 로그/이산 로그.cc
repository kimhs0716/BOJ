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

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll modpow(ll a, ll b, ll rem){ll p=1;a%=rem;for(;b;b>>=1,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
pll extended_gcd(ll a, ll b) {
    if (b==0) return {1, 0};
    auto t=extended_gcd(b, a%b);
    return {t.second, t.first-t.second*(a/b)};
}
ll modinverse(ll a, ll m) {
    return (extended_gcd(a, m).first%m+m)%m;
}

struct DM{
    static constexpr ll X=1e5;
    ll mod;
    unordered_map<ll,ll> ht;
    vl aXe, iaXe;
    DM(ll Q):mod(Q),aXe(X),iaXe(X){}
    ll discrete_log(ll B,ll N){
        ht.clear();
        ll cur=1;
        for(ll j=0;j<X;j++){if(!ht.count(cur))ht[cur]=j;cur=cur*B%mod;}
        ll gx=modpow(B,X,mod);
        aXe[0]=1;
        for(ll i=1;i<X;i++)aXe[i]=aXe[i-1]*gx%mod;
        ll igx=[&]{auto [u,v]=extended_gcd(gx,mod);ll t=u%mod;return t<0?t+mod:t;}();
        iaXe[0]=1;
        for(ll i=1;i<X;i++)iaXe[i]=iaXe[i-1]*igx%mod;
        for(ll i=0;i<X;i++){
            ll need=N*iaXe[i]%mod;
            auto it=ht.find(need);
            if(it!=ht.end())return i*X+it->second;
        }
        return -1;
    }

    ll discrete_root(ll A,ll e){
        ll g=gcd(e,mod-1);
        if(g==1){
            auto [x,y]=extended_gcd(e,mod-1);
            ll ie=x%(mod-1);
            if(ie<0)ie+=mod-1;
            return modpow(A,ie,mod);
        }
        ll t=0,s=mod-1;
        while(s%e==0){s/=e;t++;}
        if(modpow(A,(mod-1)/e,mod)!=1)return -1;
        ll r=2;
        while(modpow(r,mod-1,mod)!=1||modpow(r,s,mod)==1)r++;
        ll alpha=discrete_log(r,A);
        if(alpha<0)return -1;
        ll x0=alpha/e;
        for(ll k=0;k<e;k++){
            ll c=modpow(r,x0+k*s,mod);
            if(modpow(c,e,mod)==A)return c;
        }
        return -1;
    }
};



void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll P, B, N;
    while(cin>>P>>B>>N){
        DM dm(P);
        ll ans = dm.discrete_log(B, N);
        if (ans==-1) cout<<"no solution\n";
        else cout<<ans<<endl;
    }
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