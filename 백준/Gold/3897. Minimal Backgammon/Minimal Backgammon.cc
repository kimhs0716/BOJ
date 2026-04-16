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
constexpr ll INF = 2e18+7;

void preprocess() {
    ll i, j, k;
    cout<<fixed;
    cout.precision(6);
}

void solve(ll testcase) {
    ll i, j;
    while (true) {
        ll n, t, ln, bn; cin>>n>>t>>ln>>bn;
        if (n==0) break;
        set<ll> l, b;
        while (ln--) {
            ll x; cin>>x;
            l.insert(x);
        }
        while (bn--) {
            ll x; cin>>x;
            b.insert(x);
        }
        vector<ld> arr(n+1), larr(n+1), narr(n+1), nlarr(n+1);
        ld ans = 0;
        arr[0] = 1;
        while (t--) {
            // cout<<reduce(arr.begin(), arr.end(), 0.0)+reduce(larr.begin(), larr.end(), 0.0)<<endl;
            // for (auto x: arr) cout<<x<<' '; cout<<endl;
            // for (auto x: larr) cout<<x<<' '; cout<<endl<<endl;
            for (i=0;i<n;i++) {
                for (j=1;j<=6;j++) {
                    ll k = i+j;
                    if (k>n) k = 2*n-k;
                    if (l.contains(k)) nlarr[k] += arr[i] * 1.0/6;
                    else if (b.contains(k)) narr[0] += arr[i] * 1.0/6;
                    else narr[k] += arr[i] * 1.0/6;
                }
            }
            for (i=0;i<n;i++) {
                if (l.contains(i)) {
                    narr[i] = larr[i];
                }
            }
            swap(narr, arr);
            swap(nlarr, larr);
            fill(narr.begin(), narr.end(), 0);
            fill(nlarr.begin(), nlarr.end(), 0);
            ans += arr[n];
        }
        cout<<ans<<endl;
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