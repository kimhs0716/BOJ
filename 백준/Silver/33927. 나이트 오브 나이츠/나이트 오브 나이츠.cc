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

vector<vector<vl>> mask1 =
    {
        {
            {1}
        }
    };
vector<vector<vl>> mask2 =
    {
        {
            {1, 1},
            {1, 1},
        }
    };
vector<vector<vl>> mask3 =
    {
        {
            {1, 1, 1},
            {0, 1, 0},
            {0, 0, 0},
        },
        {
            {1, 1, 0},
            {1, 1, 0},
            {0, 0, 0},
        },
        {
            {0, 1, 0},
            {1, 1, 1},
            {0, 1, 0},
        },
        {
            {1, 0, 1},
            {0, 1, 0},
            {1, 0, 1},
        },
    };
vector<vector<vl>> mask4 =
    {
        {
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
        },
        {
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
        },
        {
            {0, 1, 0, 0},
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0},
        },
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
        },
        {
            {1, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 1},
        },
        {
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 1, 0, 1},
        },
        {
            {0, 1, 0, 1},
            {1, 0, 1, 0},
            {0, 1, 0, 1},
            {1, 0, 1, 0},
        },
        {
            {1, 1, 1, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {1, 1, 1, 1},
        },
        {
            {1, 1, 0, 1},
            {1, 0, 0, 0},
            {0, 0, 0, 1},
            {1, 0, 1, 1},
        },
    };

vector masks { mask1, mask2, mask3, mask4 };

void rotate(vector<vl> &arr) {
    ll n = arr.size();
    vector temp(n, vl(n));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            temp[i][j] = arr[n-j-1][i];
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

void flip1(vector<vl> &arr) {
    ll n = arr.size();
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; 2 * j < n; j++) {
            swap(arr[i][j], arr[i][n-j-1]);
        }
    }
}

void flip2(vector<vl> &arr) {
    ll n = arr.size();
    for (ll i = 0; 2 * i < n; i++) {
        for (ll j = 0; j < n; j++) {
            swap(arr[i][j], arr[n-i-1][j]);
        }
    }
}

ll check(vector<vl> &score, vector<vl> &mask) {
    ll ret = 0, n = score.size(), cur;
    for (ll i = 0; i < 4; i++) {
        cur = 0;
        for (ll j = 0; j < n; j++) {
            for (ll k = 0; k < n; k++) {
                cur += score[j][k] * mask[j][k];
            }
        }
        ret = max<ll>(ret, cur);

        flip1(score);
        cur = 0;
        for (ll j = 0; j < n; j++) {
            for (ll k = 0; k < n; k++) {
                cur += score[j][k] * mask[j][k];
            }
        }
        ret = max<ll>(ret, cur);

        flip2(score);
        cur = 0;
        for (ll j = 0; j < n; j++) {
            for (ll k = 0; k < n; k++) {
                cur += score[j][k] * mask[j][k];
            }
        }
        ret = max<ll>(ret, cur);

        flip1(score);
        cur = 0;
        for (ll j = 0; j < n; j++) {
            for (ll k = 0; k < n; k++) {
                cur += score[j][k] * mask[j][k];
            }
        }
        ret = max<ll>(ret, cur);

        flip2(score);
        cur = 0;
        for (ll j = 0; j < n; j++) {
            for (ll k = 0; k < n; k++) {
                cur += score[j][k] * mask[j][k];
            }
        }
        ret = max<ll>(ret, cur);

        rotate(score);

        // for (auto &i: score) {
        //     for (auto j: i) cout << j << ' ';
        //     cout << endl;
        // }
        // cout << endl;
    }

    return ret;
}

void solve(ll testcase){
    ll n; cin >> n;
    ll ans = 0;
    vector score(n, vl(n));
    for (auto &i: score) for (auto &j: i) cin >> j;
    for (auto &mask: masks[n-1]) ans = max<ll>(ans, check(score, mask));
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