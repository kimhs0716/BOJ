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

const ld eps = 1e-9;

inline ll diff(ld lhs, ld rhs) {
    if (lhs-eps<rhs && rhs<lhs+eps) return 0;
    return lhs<rhs ? -1 : 1;
}
inline bool is_between(ld check, ld a, ld b) {
    if (a<b) return a-eps<check && check<b+eps;
    return b-eps<check && check<a+eps;
}

struct Point {
    ld x, y;
    bool operator==(const Point& o) const {
        return diff(x,o.x)==0 && diff(y, o.y)==0;
    }
    Point operator+(const Point& o) const {
        return Point{ x+o.x, y+o.y };
    }
    Point operator -(const Point& o) const {
        return Point{ x-o.x, y-o.y };
    }
    Point operator*(ld t) const {
        return Point{ x*t, y*t };
    }
};

struct Line {
    Point pos, dir;
};

// 외적
inline ld outer(const Point& a, const Point& b) {
    return a.x*b.y-a.y*b.x;
}

inline ll ccw(const Point& a, const Point& b, const Point& c) {
    // (b−a)×(c−a) 의 부호
    return diff( outer(b-a, c-a), 0 );
}

// 점 r 이 선분[p, q] 위에 있는지?
bool onSegment(const Point& p, const Point& q, const Point& r) {
    if (ccw(p,q,r) != 0) return false;
    // r 의 x, y 가 p와 q의 박스 안에 들어오는지
    return r.x >= min(p.x,q.x) - eps && r.x <= max(p.x,q.x) + eps
        && r.y >= min(p.y,q.y) - eps && r.y <= max(p.y,q.y) + eps;
}

// 세그먼트 a=(a1->a2), b=(b1->b2) 교차 판정
bool segmentsIntersect(const Line& l1, const Line& l2) {
    Point a1 = l1.pos;
    Point a2 = l1.dir;
    Point b1 = l2.pos;
    Point b2 = l2.dir;

    ll o1 = ccw(a1, a2, b1);
    ll o2 = ccw(a1, a2, b2);
    ll o3 = ccw(b1, b2, a1);
    ll o4 = ccw(b1, b2, a2);

    // 1) 일반 교차: 서로 다른 직선이고, 양쪽이 안쪽에 들어올 때
    if (o1 * o2 < 0 && o3 * o4 < 0)
        return true;

    // 2) 특수 교차: 한 점이 다른 세그먼트 위에 딱 붙어 있을 때
    if (o1 == 0 && onSegment(a1, a2, b1)) return true;
    if (o2 == 0 && onSegment(a1, a2, b2)) return true;
    if (o3 == 0 && onSegment(b1, b2, a1)) return true;
    if (o4 == 0 && onSegment(b1, b2, a2)) return true;

    return false;
}


//Usage: DSU dsu(V); ll root = dsu._find(node); dsu._union(node,node);
// O(alpha(V))
struct DSU {
    vl par, sz;
    ll cnt;

    DSU(ll n) : cnt(n) {
        par.resize(n+1);
        sz.assign(n+1,1);
        iota(par.begin(),par.end(),0);
    }
    ll _find(ll x) {
        if (par[x]==x) return x;
        return par[x]=_find(par[x]);
        //for RollBack
        //return _find(par[x]);
    }
    pll _union(ll x,ll y){
        x=_find(x);
        y=_find(y);
        if (x==y) return {-1,-1};
        if (sz[x]<sz[y]) swap(x,y);
        par[y]=x;
        sz[x]+=sz[y];
        cnt--;
        return {x,y};
    }
    void _delete(ll x, ll y){
        sz[x]-=sz[y];
        par[y]=y;
    }
};

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase){
    ll i, j;
    ll n; cin>>n;
    DSU dsu(n);
    vector<Line> arr(n);
    for (i=0;i<n;i++) {
        ll x, y;
        cin>>x>>y;
        Point p1(x, y);
        cin>>x>>y;
        Point p2(x, y);
        arr[i] = Line(p1, p2);
    }
    for (i=0;i<n;i++) {
        for (j=i+1;j<n;j++) {
            if (segmentsIntersect(arr[i], arr[j])) {
                dsu._union(i, j);
                // cout<<i<<' '<<j<<endl;
            }
        }
    }
    cout<<dsu.cnt<<endl;
    cout<<*max_element(dsu.sz.begin(), dsu.sz.end())<<endl;
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