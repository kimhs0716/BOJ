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

// Usage: LCA lca(V,tree); ll anc = lca.solve(u,v);
// O(logV)
// memo : 0-indexed

struct LCA {
    ll MAXLN;
    vl depth; vvl anc;

    LCA(ll n, vvl& tree){
        ll root = 0;
        depth.assign(n,0);
        MAXLN=1;
        while ((1<<MAXLN)<=n) ++MAXLN;
        anc.assign(MAXLN,vl(n));

        function<void(ll,ll)> dfs4lca = [&](ll node,ll parent) {
            for (ll next: tree[node]) {
                if (next==parent) continue;
                depth[next]=depth[node]+1;
                anc[0][next]=node;
                dfs4lca(next, node);
            }
        };

        dfs4lca(root,-1);
        anc[0][root]=root;
        for (ll i=1;i<MAXLN;++i)
            for (ll j=0;j<n;++j)
                anc[i][j]=anc[i-1][anc[i-1][j]];
    }

    ll solve(ll u, ll v){
        if (depth[u]<depth[v]) swap(u, v);
        if (depth[u]>depth[v]) {
            for (ll i=MAXLN-1;i>=0;--i)
                if (depth[u]-(1<<i) >= depth[v])
                    u=anc[i][u];
        }
        if (u==v) return u;
        for (ll i=MAXLN-1;i>=0;--i) {
            if (anc[i][u]!=anc[i][v]) {
                u=anc[i][u];
                v=anc[i][v];
            }
        }
        return anc[0][u];
    }
};

void solve(ll testcase){
    ll i, j, k;
    ll n; cin>>n;
    vvl tree(n);
    for (i=0;i<n-1;i++) {
        ll u, v; cin>>u>>v;
        --u, --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    LCA lca(n, tree);
    ll m; cin>>m;
    while (m--) {
        ll u, v; cin>>u>>v;
        cout<<lca.solve(u-1,v-1)+1<<'\n';
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