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

struct UF {
    ll n;
    vl grp, sz;
    UF (ll n) : n(n), grp(n), sz(n, 1) {
        iota(grp.begin(), grp.end(), 0);
    }
    ll find(ll x) {
        if (x == grp[x]) return x;
        return grp[x] = find(grp[x]);
    }
    void join(ll x, ll y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        grp[y] = x;
    }
};

using edge = array<ll, 3>;

void solve(ll testcase){
    ll n, m; cin >> n >> m;
    vector<edge> edges;
    for (ll i = 0; i < m; i++) {
        ll x, y, w; cin >> x >> y >> w;
        --x, --y;
        edges.push_back({x, y, w});
    }
    sort(edges.begin(), edges.end(), [](const edge &a, const edge &b) {
        return a[2] > b[2];
    });
    UF uf(n);
    ll bottleneck = INF;
    for (auto e: edges) {
        auto &[x, y, w] = e;
        bottleneck = min<ll>(bottleneck, w);
        uf.join(x, y);
        if (uf.sz[uf.find(x)] == n) break;
    }
    while (edges.back()[2] < bottleneck) edges.pop_back();
    reverse(edges.begin(), edges.end());
    // cout << bottleneck << endl;
    vector<edge> mst;
    uf = UF(n);
    for (auto &e: edges) {
        auto &[x, y, w] = e;
        if (uf.find(x) == uf.find(y)) continue;
        uf.join(x, y);
        mst.push_back(e);
    }

    reverse(mst.begin(), mst.end());
    // for (auto &e: mst) cout << e[0] << ' ' << e[1] << ' ' << e[2] << endl;

    uf = UF(n);
    ll ans = 0;
    for (auto &e : mst) {
        ll u = e[0], v = e[1], w = e[2];
        u = uf.find(u), v = uf.find(v);
        if (u == v) continue;
        ans += w * uf.sz[u] * uf.sz[v];
        uf.join(u, v);
    }
    cout << ans << endl;

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