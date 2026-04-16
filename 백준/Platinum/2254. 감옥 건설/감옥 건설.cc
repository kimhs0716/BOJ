#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;
using vd = vector<ld>;
using ull = unsigned long long;
using vp = vector<pll>;
using vvp = vector<vp>;
using tlll = array<ll, 3>;

#define endl '\n'

void setup() {
#ifdef KIMHS
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}

template <typename T>
istream& operator>>(istream &is, vector<T> &arr) {
    for (auto &x: arr) is>>x;
    return is;
}

template <typename T>
ostream& operator<<(ostream &os, vector<T> &arr) {
    if (arr.size()==0) return os<<"()";
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) os<<arr[i]<<' ';
    if (arr.size()) os<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e18;
constexpr ll MAX = 100'000;

void preprocess() {
    ll i, j, k;
}

const ld eps = 1e-9;
inline ll diff(ld lhs, ld rhs) {
    if (lhs-eps<rhs && rhs<lhs+eps) return 0;
    return lhs<rhs ? -1 : 1;
}
struct Point {
    ld x, y;
    bool operator==(const Point& o) const {
        return diff(x,o.x)==0 && diff(y, o.y)==0;
    }
    Point operator+(const Point& o) const {
        return Point{ x+o.x, y+o.y };
    }
    Point operator-(const Point& o) const {
        return Point{ x-o.x, y-o.y };
    }
    Point operator*(ld t) const {
        return Point{ x*t, y*t };
    }
    friend istream& operator>>(istream& is, Point& p) {
        return is >> p.x >> p.y;
    }
};

inline ld outer(const Point& a, const Point& b) {
    return a.x*b.y-a.y*b.x;
}

// a->b->c rotation orientation, (+) CCW, (-) CW, (0) collinear
inline ll ccw(const Point& a, const Point& b, const Point& c) {
    return diff(outer(b-a, c-a), 0);
}

// Usage: Find the smallest convex polygon that encloses all points
// O(NlogN)
void getConvexHull(vector<Point>& pt, vector<Point>& convex_hull) {
    sort(pt.begin(), pt.end(), [](const Point& a, const Point& b) {
        return a.x==b.x ? a.y<b.y : a.x<b.x;
    });
    vector<Point> up, lo;
    for (const auto& p : pt) {
        while (up.size() >= 2 && ccw(*++up.rbegin(), *up.rbegin(), p) >= 0) up.pop_back();
        while (lo.size() >= 2 && ccw(*++lo.rbegin(), *lo.rbegin(), p) <= 0) lo.pop_back();
        up.push_back(p);
        lo.push_back(p);
    }
    up.insert(up.end(), ++lo.rbegin(), --lo.rend());
    swap(up, convex_hull);
}

// Usage: Is pointer in polygon?
// O(N)
bool is_in_polygon(Point p, vector<Point>& poly) {
    ll wn = 0;
    for (ll i=0; i<poly.size(); ++i) {
        ll ni = i+1==poly.size() ? 0 : i+1;
        if (poly[i].y<=p.y) {
            if (poly[ni].y>p.y && ccw(poly[i], poly[ni], p)>0) ++wn;
        }
        else if (poly[ni].y<=p.y && ccw(poly[i], poly[ni], p)<0) --wn;
    }
    return wn != 0;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    ll px, py; cin>>px>>py;
    Point p(px, py);
    vector<Point> arr(n);
    for (auto &pp: arr) cin>>pp.x>>pp.y;
    ll ans=0;
    while (true) {
        // cout<<arr.size()<<endl;
        if (arr.size()<=2) break;
        vector<Point> ch, narr;
        getConvexHull(arr, ch);
        if (!is_in_polygon(p, ch)) break;
        for (auto &pp : arr) if (!count(ch.begin(), ch.end(), pp)) narr.push_back(pp);
        swap(arr, narr);
        ans++;
    }
    cout<<ans<<endl;
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    // cin >> testcase;
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
    }
}

