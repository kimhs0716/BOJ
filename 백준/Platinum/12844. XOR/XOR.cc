#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
typedef unsigned long long ull;
typedef __float128 LD;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_set
    = tree<T, null_type, less<>, rb_tree_tag,
        tree_order_statistics_node_update>;
template<typename T> using ordered_multiset
    = tree<T, null_type, less_equal<>, rb_tree_tag,
        tree_order_statistics_node_update>;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)

#define debug if constexpr (!ndebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (!ndebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (!ndebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#define endl '\n'

#ifndef KIMHS
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;a%=rem;for(;b;b>>=1,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
pll extended_gcd(ll a, ll b){if(b == 0)return {1, 0};auto t = extended_gcd(b, a % b);return {t.second, t.first - t.second * (a / b)};}
ll modinverse(ll a, ll m){return (extended_gcd(a, m).first % m + m) % m;}

void setup() {
    if(!ndebug) {
        freopen("boj.in", "r", stdin);
        freopen("boj.out", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1e18;

// usage: LAZY(n, arr); update(qs, qe, val); ll sum = query(qs, qe);
// memo : 0-indexed
struct LAZY {
    ll n;
    vl seg, lazy, arr;

    LAZY(ll n, vl& arr): n(n),arr(arr),seg(n<<2),lazy(n<<2){
        init(1,0,n-1);
    }

    void init(ll node,ll l,ll r) {
        if (l==r) {
            seg[node]=arr[l];
            return;
        }
        ll m=(l+r)>>1;
        init(node<<1,l,m);
        init(node<<1|1,m+1,r);
        seg[node]=seg[node<<1]^seg[node<<1|1];
    }

    void relax(ll node, ll l, ll r) {
        if (lazy[node]==0) return;
        if (l<r) {
            ll m = (l+r)>>1;
            seg[node<<1]^=((m-l+1)&1)*lazy[node];
            lazy[node<<1]^=lazy[node];
            seg[node<<1|1]^=((r-m)&1)*lazy[node];
            lazy[node<<1|1]^=lazy[node];
        }
        lazy[node]=0;
    }

    ll range_sum(ll node, ll l, ll r, ll s, ll e) {
        if (r<s||e<l) return 0;
        if (s<=l&&r<=e) return seg[node];
        relax(node,l,r);
        ll m=(l+r)>>1;
        return range_sum(node<<1,l,m,s,e) ^ range_sum(node<<1|1,m+1,r,s,e);
    }

    void range_update(ll node, ll l, ll r, ll s, ll e, ll val) {
        if (r<s||e<l) return;
        if (s<=l&&r<=e) {
            seg[node]^=((r-l+1)&1)*val;
            lazy[node]^=val;
            return;
        }
        relax(node,l,r);
        ll m=(l+r)>>1;
        range_update(node<<1,l,m,s,e,val);
        range_update(node<<1|1,m+1,r,s,e,val);
        seg[node]=seg[node<<1]^seg[node<<1|1];
    }
    void update(ll s,ll e,ll val){range_update(1,0,n-1,s,e,val);}
    ll query(ll s,ll e){return range_sum(1,0,n-1,s,e);}
};
void preprocess() {
    ll i, j, k;

}

void solve(ll testcase){
    ll i, j, k;
    ll n; cin>>n;
    vl arr(n);
    for (auto &x: arr) cin>>x;
    LAZY lst(n, arr);
    ll q; cin>>q;
    while (q--) {
        ll type; cin>>type;
        if (type==1) {
            cin>>i>>j>>k;
            lst.update(i, j, k);
        }
        else {
            cin>>i>>j;
            cout<<lst.query(i, j)<<endl;
        }
    }
}

int main() {
    setup();
    preprocess();
    ll t = 1;
    // cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++){
        solve(testcase);
    }
    return 0;
}