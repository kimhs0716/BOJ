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

struct Matrix {
    ll n;
    vector<vl> arr;
    Matrix(ll n): n(n) {
        arr = vector<vl>(n, vl(n));
    }
};

Matrix matmul(const Matrix &a, const Matrix &b) {
    ll i, j, k;
    ll n=a.arr.size();
    Matrix ret(n);
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            for (k=0;k<n;k++) {
                ret.arr[i][j]+=a.arr[i][k]*b.arr[k][j];
                ret.arr[i][j] %= MOD;
            }
        }
    }
    return ret;
}

Matrix matpow(const Matrix &a, ll b) {
    ll n=a.arr.size();
    Matrix ret(n), cur(a);
    for (ll i=0;i<n;i++) ret.arr[i][i]=1;
    while (b) {
        if (b&1) ret=matmul(ret, cur);
        cur=matmul(cur, cur);
        b>>=1;
    }
    return ret;
}

void solve(ll testcase) {
    ll i, j, k;
    ll t, n, m; cin>>t>>n>>m;
    vector<Matrix> arr(t, Matrix(n));
    for (i=0;i<t;i++) {
        cin>>k;
        while (k--) {
            ll a, b, c; cin>>a>>b>>c;
            arr[i].arr[a-1][b-1]=c;
        }
    }
    Matrix cycle(arr[0]);
    for (i=1;i<t;i++) {
        cycle=matmul(cycle, arr[i]);
    }
    Matrix ans=matpow(cycle, m/t);
    m%=t;
    for (i=0;i<m;i++) {
        ans=matmul(ans, arr[i]);
    }
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            cout<<ans.arr[i][j]<<' ';
        }
        cout<<endl;
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