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

bool check(vector<array<ll, 3>> &arr, vl &mask) {
    for (ll i=0;i<6;i++) if (arr[mask[i]][0] != arr[mask[(i+1)%6]][2]) return false;
    return true;
}

ll score(vector<array<ll, 3>> &arr, vl &mask) {
    ll sum=0;
    for (ll i=0;i<6;i++) sum+=arr[mask[i]][1];
    return sum;
}

void rotate(array<ll, 3> &t) {
    swap(t[0], t[1]);
    swap(t[2], t[1]);
}

void solve(ll testcase) {
    ll i, j;
    while (true) {
        vector<array<ll, 3>> arr(6);
        for (auto &x: arr) cin>>x[0]>>x[1]>>x[2];
        ll ans=-1;
        vl mask {0, 1, 2, 3, 4, 5};
        do {
            for (i=0;i<729;i++) {
                if (check(arr, mask))
                    ans = max(ans, score(arr, mask));
                rotate(arr[0]);
                if (i%3==0) rotate(arr[1]);
                if (i%9==0) rotate(arr[2]);
                if (i%27==0) rotate(arr[3]);
                if (i%81==0) rotate(arr[4]);
                if (i%243==0) rotate(arr[5]);
            }
        } while (next_permutation(mask.begin(), mask.end()));
        if (ans==-1) cout<<"none\n";
        else cout<<ans<<endl;
        char nxt; cin>>nxt;
        if (nxt=='$') break;
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