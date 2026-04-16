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
// typedef __float128 LD;
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

constexpr ll INF = 0x3434343434;
constexpr ll MOD = 1'000'000'007;

void solve(ll testcase){
    ll r, c; cin >> r >> c;
    vector<vl> arr(r, vl(c));
    for (vl &i: arr) for (ll &j: i) cin >> j;
    ll x; cin >> x;
    vector<vl> cache(r, vl(c, -1));
    cache[r-1][c-1] = 1;
    auto f = [&](auto self, ll r, ll c) -> bool {
        // cout << r << ' ' << c << endl;
        if (r == arr.size() - 1 && c == arr[0].size() - 1) return true;
        if (cache[r][c] == -1) {
            cache[r][c] = false;
            for (ll dr = -x; dr <= x; dr++) {
                for (ll dc = -x; dc <= x; dc++) {
                    if (abs(dr) + abs(dc) > x) continue;
                    if (dr == 0 && dc == 0) continue;
                    ll nr = r + dr, nc = c + dc;
                    if (nr < 0 || nr >= arr.size()) continue;
                    if (nc < 0 || nc >= arr[0].size()) continue;
                    if (arr[r][c] != arr[nr][nc]) continue;
                    if (self(self, nr, nc)) {
                        return cache[r][c] = true;
                    }
                }
            }
        }
        return cache[r][c];
    };
    cout << (f(f, 0, 0) ? "ALIVE" : "DEAD") << endl;
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