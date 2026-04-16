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
}

vector<vvl> masks {
    {
        {1, 1, 1, 1, 1, 1},
    },
    {
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1},
    },
    {
        {0, 1, 0, 0, 0},
        {1, 1, 1, 1, 1},
    },
    {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
    },
    {
        {1, 1, 0, 0, 0},
        {0, 1, 1, 1, 1},
    },
    {
        {1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1},
    },
    {
        {1, 1, 0, 0},
        {1, 1, 1, 1},
    },
    {
        {1, 0, 1, 0},
        {1, 1, 1, 1},
    },
    {
        {1, 0, 0, 1},
        {1, 1, 1, 1},
    },
    {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
    },
    {
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 1, 1},
    },
    {
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 1, 1},
    },
    {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 0},
    },
    {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 1, 0, 0},
    },
    {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 1, 0},
    },
    {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 1},
    },
    {
        {0, 1, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 1, 0},
    },
    {
        {0, 1, 0, 0},
        {1, 1, 1, 1},
        {0, 1, 0, 0},
    },
    {
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 1},
    },
    {
        {1, 1, 0, 1},
        {0, 1, 1, 1},
    },
    {
        {1, 1, 1, 0},
        {0, 1, 1, 1},
    },
    {
        {1, 1, 0, 0},
        {0, 1, 1, 1},
        {0, 1, 0, 0},
    },
    {
        {1, 1, 0, 0},
        {0, 1, 1, 1},
        {0, 0, 1, 0},
    },
    {
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 1},
    },
    {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 1},
    },
    {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 1},
    },
    {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
    },
    {
        {1, 1, 1},
        {1, 1, 1},
    },
    {
        {1, 1, 0},
        {1, 1, 1},
        {1, 0, 0},
    },
    {
        {1, 1, 0},
        {1, 0, 0},
        {1, 1, 1},
    },
    {
        {1, 1, 0},
        {0, 1, 0},
        {1, 1, 1},
    },
    {
        {1, 1, 0},
        {0, 1, 1},
        {1, 1, 0},
    },
    {
        {0, 0, 1},
        {0, 1, 1},
        {1, 1, 1},
    },
    {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 1},
    },
    {
        {1, 1, 0},
        {0, 1, 1},
        {0, 1, 1},
    },
};

void flip1(vvl &arr) {
    ll i, j;
    ll r = arr.size(), c = arr[0].size();
    vvl ret(r, vl(c));
    for (i=0;i<r;i++) for (j=0;j<c;j++) ret[i][j] = arr[i][c-j-1];
    swap(arr, ret);
}

void flip2(vvl &arr) {
    ll i, j;
    ll r = arr.size(), c = arr[0].size();
    vvl ret(r, vl(c));
    for (i=0;i<r;i++) for (j=0;j<c;j++) ret[i][j] = arr[r-i-1][j];
    swap(arr, ret);
}

void rotate(vvl &arr) {
    ll i, j;
    ll r = arr.size(), c = arr[0].size();
    vvl ret(c, vl(r));
    for (i=0;i<r;i++) for (j=0;j<c;j++) ret[c-j-1][i] = arr[i][j];
    swap(arr, ret);
}

ll score(vvl &arr, vvl &mask) {
    ll i, j, ii, jj;
    ll r = arr.size(), c = arr[0].size();
    ll rr = mask.size(), cc = mask[0].size();
    ll ret = 0;
    for (i=0;i<=r-rr;i++) {
        for (j=0;j<=c-cc;j++) {
            ll s = 0;
            for (ii=0;ii<rr;ii++) for (jj=0;jj<cc;jj++) if (mask[ii][jj]) s += arr[i+ii][j+jj];
            ret = max<ll>(ret, s);
        }
    }
    return ret;
}

void solve(ll testcase){
    ll i, j;
    ll r, c; cin>>r>>c;
    vvl arr(r, vl(c));
    for (auto &x: arr) {
        for (auto &y: x) cin>>y;
    }
    ll ans = 0;
    for (auto &mask: masks) {
        for (i=0;i<4;i++) {
            ans = max<ll>(ans, score(arr, mask));
            rotate(mask);
        }
        flip1(mask);
        for (i=0;i<4;i++) {
            ans = max<ll>(ans, score(arr, mask));
            rotate(mask);
        }
        flip2(mask);
        for (i=0;i<4;i++) {
            ans = max<ll>(ans, score(arr, mask));
            rotate(mask);
        }
        flip1(mask);
        for (i=0;i<4;i++) {
            ans = max<ll>(ans, score(arr, mask));
            rotate(mask);
        }
        flip2(mask);
    }
    cout<<ans<<endl;
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