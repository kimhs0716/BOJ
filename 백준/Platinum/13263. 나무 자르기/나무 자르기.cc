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

// Convex Hull Optimization
// Memo: O(n^2) -> O(n*logn), 아래 조건 중 하나 만족해야 함
// Memo: D[i] = max[j<i](D[j]+b[j]*a[i]), (b[k]<=b[k+1])
// Memo: D[i] = min[j<i](D[j]+b[j]*a[i]), (b[k]>=b[k+1])
struct CHT {
    struct Line {
        ll m, b;   // y = m*x + b
    };
    vector<Line> lines;
    vl xs;
    ll intersect(Line &l1, Line &l2) {
        ll num = l1.b - l2.b;
        ll den = l2.m - l1.m;
        // min인 경우 num과 den에 -1을 곱함
        num*=-1, den*=-1;
        return num>=0 ? (num+den-1)/den : num/den;
    }
    void addLine(ll m, ll b) {
        if (lines.size() && lines.back().m==m) {
            // if (lines.back().b>=b) return; // min인 경우 부등호 반대로
            if (lines.back().b<=b) return; // min인 경우 부등호 반대로
            lines.pop_back();
            xs.pop_back();
        }
        Line L{m,b};
        while (lines.size()) {
            ll x=intersect(lines.back(), L);
            if (x<=xs.back()) {
                lines.pop_back();
                xs.pop_back();
            }
            else break;
        }
        if (lines.empty()) {
            lines.push_back(L);
            xs.push_back(LLONG_MIN);
        }
        else {
            lines.push_back(L);
            xs.push_back(intersect(lines[lines.size()-2], L));
        }
    }
    ll query(ll x) {
        ll idx=int(upper_bound(xs.begin(), xs.end(), x)-xs.begin())-1;
        return lines[idx].m*x+lines[idx].b;
    }
};


void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j;
    ll n; cin>>n;
    vl a(n), b(n);
    for (auto &x: a) cin>>x;
    for (auto &x: b) cin>>x;
    CHT cht;
    vl dp(n);
    cht.addLine(b[0], dp[0]);
    for (i=0;i<n;i++) {
        dp[i] = cht.query(a[i]);
        cht.addLine(b[i], dp[i]);
    }
    // for (auto x: dp) cout<<x<<' '; cout<<endl;
    cout<<dp.back()<<endl;
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