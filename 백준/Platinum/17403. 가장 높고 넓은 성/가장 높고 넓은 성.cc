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
ostream& operator<<(ostream &os, vector<T> arr) {
    if (arr.size()==0) return os<<"()";
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) os<<arr[i]<<' ';
    if (arr.size()) os<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e15;

const ld eps = 1e-9;
inline ll diff(ld lhs, ld rhs) {
    if (lhs-eps<rhs && rhs<lhs+eps) return 0;
    return lhs<rhs ? -1 : 1;
}
struct Point {
    ld x, y;
    ll idx;
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
struct Line {
    Point pos, dir;
    Line()=default;
    Line(const Point& a, const Point& b): pos(a), dir(b - a) {}
    friend istream& operator>>(istream& is, Line& l) {
        Point p1, p2;
        is >> p1 >> p2;
        l.pos = p1;
        l.dir = Point{ p2.x-p1.x, p2.y-p1.y };
        return is;
    }
};
struct Circle {
    Point center;
    ld r;
};
inline ld inner(const Point& a, const Point& b) {
    return a.x*b.x+a.y*b.y;
}
inline ld outer(const Point& a, const Point& b) {
    return a.x*b.y-a.y*b.x;
}
// point-line positional relationship, (+) l, (-) r, (0) on line
inline ll ccw_line(const Line& line, const Point& point) {
    return diff(outer(line.dir, point-line.pos), 0);
}
// a->b->c rotation orientation, (+) CCW, (-) CW, (0) collinear
inline ll ccw(const Point& a, const Point& b, const Point& c) {
    return diff(outer(b-a, c-a), 0);
}
inline bool is_between(ld check, ld a, ld b) {
    if (a<b) return a-eps<check && check<b+eps;
    return b-eps<check && check<a+eps;
}
// Euclidean distance
inline ld dist(const Point& a, const Point& b) {
    return sqrt(inner(a-b, a-b));
}
// Euclidean distance squared
inline ld dist2(const Point &a, const Point &b) {
    return inner(a-b, a-b);
}

// Usage: Find the smallest convex polygon that encloses all points
// O(NlogN)
void getConvexHull(vector<Point>& pt, vl &used, vector<Point>& convex_hull) {
    sort(pt.begin(), pt.end(), [&used](const Point& a, const Point& b) {
        if (used[a.idx] || used[b.idx]) return used[a.idx] < used[b.idx];
        return a.x==b.x ? a.y<b.y : a.x<b.x;
    });
    vector<Point> up, lo;
    for (const auto& p : pt) {
        if (used[p.idx]) continue;
        while (up.size() >= 2 && ccw(*++up.rbegin(), *up.rbegin(), p) >= 0) up.pop_back();
        while (lo.size() >= 2 && ccw(*++lo.rbegin(), *lo.rbegin(), p) <= 0) lo.pop_back();
        up.push_back(p);
        lo.push_back(p);
    }
    // rotating calipers
    // Usage: Get all antipodal pairs
    // O(N)
    for (ll i=0, j=(ll)lo.size()-1; i+1<up.size() || j > 0;) {
        // get_pair(up[i], lo[j]); // DO WHAT YOU WANT
        if (i + 1 == up.size()) --j;
        else if (j == 0) ++i;
        else if ((up[i+1].y - up[i].y) * (lo[j].x - lo[j-1].x) >
        (up[i+1].x - up[i].x) * (lo[j].y - lo[j-1].y))++i;
        else --j;
    }
    up.insert(up.end(), ++lo.rbegin(), --lo.rend());
    swap(up, convex_hull);
}

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    vector<Point> pts(n);
    vl ans(n);
    for (i=0;i<n;i++) {
        cin>>pts[i];
        pts[i].idx = i;
    }
    vl used(n);
    ll cnt=0;
    for (i=0;;i++) {
        vector<Point> convex_hull;
        if (n-cnt<=2) break;
        getConvexHull(pts, used, convex_hull);
        if (convex_hull.size()<=2) break;
        for (auto p: convex_hull) {
            // cout<<p.x<<' '<<p.y<<' '<<p.idx<<endl;
            used[p.idx] = 1;
            ans[p.idx] = i+1;
            cnt++;
        }
    }
    for (auto x: ans) cout<<x<<' '; cout<<endl;
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

