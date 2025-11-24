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

#ifdef ONLINE_JUDGE
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
    // ll i, j, k;

}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1e10;

struct MergeSortTree {
    ll n;
    vector<vl> tree;
    vl &data;
    MergeSortTree(vl &data) : data(data), n(data.size()), tree(n<<2) {
        treeInit(1, 0, n-1);
    }
    void treeInit(ll i, ll s, ll e) {
        if (s == e) {
            tree[i].push_back(data[s]);
            return;
        }
        ll m=(s+e)>>1;
        treeInit(i<<1, s, m);
        treeInit(i<<1|1, m+1, e);
        tree[i].resize(tree[i<<1].size()+tree[i<<1|1].size());
        merge(
            tree[i<<1].begin(), tree[i<<1].end(),
            tree[i<<1|1].begin(), tree[i<<1|1].end(),
            tree[i].begin()
        );
    }
    ll treeQuery(ll i, ll s, ll e, ll l, ll r, ll k) {
        if (r<s || e<l) return 0;
        if (l<=s && e<=r) return tree[i].end() - upper_bound(tree[i].begin(), tree[i].end(), k);
        ll m=(s+e)>>1;
        return treeQuery(i<<1, s, m, l, r, k) + treeQuery(i<<1|1, m+1, e, l, r, k);
    }
    ll query(ll l, ll r, ll k) {
        return treeQuery(1, 0, n-1, l, r, k);
    }
};

void solve(ll testcase){
    ll n; cin >> n;
    vl arr(n);
    for (auto &i: arr) cin >> i;
    MergeSortTree tree(arr);
    ll q; cin >> q;
    while (q--) {
        ll l, r, k; cin >> l >> r >> k;
        cout << tree.query(l-1, r-1, k) << endl;
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