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

void preprocess() {
    ll i, j, k;

}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1e18;

void solve(ll testcase){
    ll i, j, k;
    ll q; cin>>q;
    ll y_sum=0, min_sum=0, max_sum=0;
    priority_queue<ll> maxheap;
    priority_queue<ll, vl, greater<ll>> minheap;
    --q;
    ll x, y, mid;
    cin>>k>>x>>y;
    mid = x;
    y_sum+=y;
    while (q--) {
        ll type; cin>>type;
        if (type == 1) {
            cin>>x>>y;
            y_sum+=y;
            if (mid<=x) {
                minheap.push(x);
                min_sum+=x;
                if (minheap.size() == maxheap.size() + 2) {
                    ll t = minheap.top();
                    min_sum-=t;
                    max_sum+=mid;
                    maxheap.push(mid);
                    minheap.pop();
                    mid=t;
                }
            }
            else {
                maxheap.push(x);
                max_sum+=x;
                if (minheap.size() == maxheap.size() - 1) {
                    ll t = maxheap.top();
                    max_sum-=t;
                    min_sum+=mid;
                    minheap.push(mid);
                    maxheap.pop();
                    mid=t;
                }
            }
        }
        else {
            cout<<mid<<' ';
            ll ans=min_sum-max_sum+y_sum;
            if (minheap.size() != maxheap.size()) ans-=mid;
            cout<<ans<<endl;
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