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

void solve(ll testcase){
    ll n, m; cin >> n >> m;
    vector<vl> arr(n, vl(m)), color(n, vl(m)), min_dp(n, vl(m)), max_dp(n, vl(m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> color[i][j];
        }
    }
    min_dp[0][0] = max_dp[0][0] = arr[0][0];
    for (ll i = 1; i < m; i++) {
        if (color[0][i]) {
            min_dp[0][i] = -max<ll>(min_dp[0][i-1] + arr[0][i], max_dp[0][i-1] + arr[0][i]);
            max_dp[0][i] = -min<ll>(min_dp[0][i-1] + arr[0][i], max_dp[0][i-1] + arr[0][i]);
        }
        else {
            min_dp[0][i] = min<ll>(min_dp[0][i-1] + arr[0][i], max_dp[0][i-1] + arr[0][i]);
            max_dp[0][i] = max<ll>(min_dp[0][i-1] + arr[0][i], max_dp[0][i-1] + arr[0][i]);
        }
    }
    for (ll i = 1; i < n; i++) {
        if (color[i][0]) {
            min_dp[i][0] = -max<ll>(min_dp[i-1][0] + arr[i][0], max_dp[i-1][0] + arr[i][0]);
            max_dp[i][0] = -min<ll>(min_dp[i-1][0] + arr[i][0], max_dp[i-1][0] + arr[i][0]);
        }
        else {
            min_dp[i][0] = min<ll>(min_dp[i-1][0] + arr[i][0], max_dp[i-1][0] + arr[i][0]);
            max_dp[i][0] = max<ll>(min_dp[i-1][0] + arr[i][0], max_dp[i-1][0] + arr[i][0]);
        }
        for (ll j = 1; j < m; j++) {
            if (color[i][j]) {
                min_dp[i][j] = -max<ll>({
                    min_dp[i-1][j] + arr[i][j], max_dp[i-1][j] + arr[i][j],
                    min_dp[i][j-1] + arr[i][j], max_dp[i][j-1] + arr[i][j],
                });
                max_dp[i][j] = -min<ll>({
                    min_dp[i-1][j] + arr[i][j], max_dp[i-1][j] + arr[i][j],
                    min_dp[i][j-1] + arr[i][j], max_dp[i][j-1] + arr[i][j],
                });
            }
            else {
                min_dp[i][j] = min<ll>({
                    min_dp[i-1][j] + arr[i][j], max_dp[i-1][j] + arr[i][j],
                    min_dp[i][j-1] + arr[i][j], max_dp[i][j-1] + arr[i][j],
                });
                max_dp[i][j] = max<ll>({
                    min_dp[i-1][j] + arr[i][j], max_dp[i-1][j] + arr[i][j],
                    min_dp[i][j-1] + arr[i][j], max_dp[i][j-1] + arr[i][j],
                });
            }
        }
    }
    cout << max_dp[n-1][m-1] << endl;
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