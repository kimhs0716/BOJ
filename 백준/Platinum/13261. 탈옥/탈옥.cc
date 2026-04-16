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

int L, G;
vector<ll> R;               // 방별 탈옥력 Ci
vector<ll> psum;            // prefix sum
vector<vector<ll>> C, D;    // C[j][i]=cost(j+1,i), D[t][i]=dp

// [l..r] 구간의 비용
inline ll cost(int l, int r) {
    ll s = psum[r] - psum[l-1];
    return s * (r - l + 1);
}

// Divide and Conquer Optimization
// Memo: D[t][i] = min[j<i](D[t-1][j] + C[j][i])
// Memo: O(kn^2) -> O(knlogn), 아래 조건 만족해야 함
// Memo: C[a][c] + C[b][d] <= C[a][d] + C[b][c], (a<=b<=c<=d)

void f(ll t, ll s, ll e, ll l, ll r){
    if(s>e) return;
    ll m=(s+e)>>1;
    ll opt=l;
    for(ll i=l;i<=r;i++){
        if(D[t-1][opt]+C[opt][m]>D[t-1][i]+C[i][m]) opt=i;
    }
    D[t][m]=D[t-1][opt]+C[opt][m];
    f(t, s, m-1, l, opt);
    f(t, m+1, e, opt, r);
}


void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j;
    cin >> L >> G;
    R.resize(L+1);
    for(int i = 1; i <= L; i++){
        cin >> R[i];
    }

    // prefix sum 계산
    psum.assign(L+1, 0);
    for(int i = 1; i <= L; i++){
        psum[i] = psum[i-1] + R[i];
    }

    // C[j][i] = cost(j+1, i) 미리 계산
    C.assign(L+1, vector<ll>(L+1, 0));
    for(int j = 0; j < L; j++){
        for(int i = j+1; i <= L; i++){
            C[j][i] = cost(j+1, i);
        }
    }

    // D[t][i] 초기화
    D.assign(G+1, vector<ll>(L+1, INF));
    // t=1 (간수 1명일 때): [1..i]를 한 명이 모두 담당
    D[1][0] = 0;
    for(int i = 1; i <= L; i++){
        D[1][i] = C[0][i];  // cost(1,i)
    }

    // t=2..G 에 대해 분할정복 최적화 실행
    for(int t = 2; t <= G; t++){
        f(t, 1, L, 0, L-1);
    }

    // 최종 답
    cout << D[G][L] << "\n";
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