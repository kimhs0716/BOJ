#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;
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
    os<<'(';
    for (auto &x: arr) os<<x<<' ';
    return os<<')';
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

const ld eps = 1e-9;
inline ll diff(ld lhs, ld rhs) {
    if (lhs-eps<rhs && rhs<lhs+eps) return 0;
    return lhs<rhs ? -1 : 1;
}

struct Point {
    ll x, y;
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

inline ld inner(const Point& a, const Point& b) {
    return a.x*b.x+a.y*b.y;
}
inline ld outer(const Point& a, const Point& b) {
    return a.x*b.y-a.y*b.x;
}

inline ld dist(const Point& a, const Point& b) {
    return sqrt(inner(a-b, a-b));
}

// a->b->c rotation orientation, (+) CCW, (-) CW, (0) collinear
inline ll ccw(const Point& a, const Point& b, const Point& c) {
    return diff(outer(b-a, c-a), 0);
}

ld max_dist=0;
Point ans_a, ans_b;
void get_pair(const Point& a, const Point& b) {
    ld d = dist(a, b);
    if (d > max_dist) {
        max_dist = d;
        ans_a = a;
        ans_b = b;
    }
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
    // rotating calipers
    // Usage: Get all antipodal pairs
    // O(N)
    for (ll i=0, j=(ll)lo.size()-1; i+1<up.size() || j > 0;) {
        get_pair(up[i], lo[j]); // DO WHAT YOU WANT
        if (i + 1 == up.size()) --j;
        else if (j == 0) ++i;
        else if ((up[i+1].y - up[i].y) * (lo[j].x - lo[j-1].x) >
        (up[i+1].x - up[i].x) * (lo[j].y - lo[j-1].y))++i;
        else --j;
    }
    up.insert(up.end(), ++lo.rbegin(), --lo.rend());
    swap(up, convex_hull);
}

void solve(ll testcase) {
    ll i, j;
    max_dist=0;
    ll n; cin>>n;
    vector<Point> pt(n), ch; cin>>pt;
    getConvexHull(pt, ch);
    cout<<ans_a.x<<' '<<ans_a.y<<' ';
    cout<<ans_b.x<<' '<<ans_b.y<<endl;
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    cin >> testcase;
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
    }
}