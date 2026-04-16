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

inline ld inner(const Point& a, const Point& b) {
    return a.x*b.x+a.y*b.y;
}

inline ld outer(const Point& a, const Point& b) {
    return a.x*b.y-a.y*b.x;
}

// a->b->c rotation orientation, (+) CCW, (-) CW, (0) collinear
inline ll ccw(const Point& a, const Point& b, const Point& c) {
    return diff(outer(b-a, c-a), 0);
}

// point-line positional relationship, (+) l, (-) r, (0) on line
inline ll ccw_line(const Line& line, const Point& point) {
    return diff(outer(line.dir, point-line.pos), 0);
}

inline bool is_between(ld check, ld a, ld b) {
    if (a<b) return a-eps<check && check<b+eps;
    return b-eps<check && check<a+eps;
}

inline ld dist(const Point& a, const Point& b) {
    return sqrt(inner(a-b, a-b));
}

// segment intersection test, ret: intersection point
// 0: no intersection, 1: single point, 2: multiple points
ll seg_seg(const Line& a, const Line& b, Point& ret) {
    ld mdet = outer(b.dir, a.dir);
    if (diff(mdet, 0) == 0) {
        if (ccw_line(a,b.pos)!=0) return 0;
        ld t0 = inner(b.pos-a.pos, a.dir)/inner(a.dir,a.dir);
        ld t1 = inner(b.pos+b.dir-a.pos,a.dir) / inner(a.dir,a.dir);
        if (t0>t1) swap(t0,t1);
        ld l=max((ld)0,t0),h=min((ld)1,t1);
        if (diff(h,l)<0) return 0;
        if (diff(h,l)>0) return 2;
        ret = a.pos+a.dir*l;
        return 1;
    }
    ld t1 = -outer(b.pos-a.pos, b.dir)/mdet;
    ld t2 = outer(a.dir, b.pos-a.pos)/mdet;
    if (!is_between(t1, 0, 1) || !is_between(t2, 0, 1)) return 0;
    ret = b.pos+b.dir*t2;
    return 1;
}

void solve(ll testcase) {
    ll i, j, k;
    Point head(0, 0);
    ll dir = 0;
    ll l, n; cin>>l>>n;
    Point c1(l+1, l+1), c2(l+1, -l-1), c3(-l-1, -l-1), c4(-l-1, l+1);
    vector<Line> body {Line(c1, c2), Line(c2, c3), Line(c3, c4), Line(c4, c1)};
    ll ans=0;
    vector<pair<ll, char>> query(n);
    for (auto &[t, d] : query) cin>>t>>d;
    query.push_back({2*l+2, 'L'});
    for (i=0;i<=n;i++) {
        auto [t, d] = query[i];
        Point nxt;
        if (dir==0) nxt = Point(head.x+t, head.y);
        else if (dir==1) nxt = Point(head.x, head.y+t);
        else if (dir==2) nxt = Point(head.x-t, head.y);
        else if (dir==3) nxt = Point(head.x, head.y-t);
        Line cur(head, nxt);
        ll mt = INF;
        for (j=0;j<body.size();j++) {
            Line b = body[j];
            Point p;
            if (auto tt = seg_seg(b, cur, p)) {
                ll d;
                if (tt==1) {
                    d = (ll)(dist(head, p) + 0.5);
                }
                else {
                    d = (ll)(min(dist(head, b.pos), dist(head, b.pos+b.dir))+0.5);
                }
                if (p == head) continue;
                // cout<<b.pos.x<<'/'<<b.pos.y<<' '<<b.dir.x<<'/'<<b.dir.y<<endl;
                // cout<<cur.pos.x<<'/'<<cur.pos.y<<' '<<cur.dir.x<<'/'<<cur.dir.y<<endl;
                // cout<<p.x<<' '<<p.y<<' '<<d<<endl;
                mt = min(mt, d);
            }
        }
        if (mt<=1e10) {
            ans += mt;
            cout<<ans<<endl;
            return;
        }
        ans += t;
        body.push_back(cur);
        head = nxt;
        if (d=='L') dir=(dir+1)%4;
        else dir=(dir+3)%4;
    }
    if (dir==0) ans += (l+1-head.x);
    if (dir==1) ans += (l+1-head.y);
    if (dir==2) ans += (head.x+l+1);
    if (dir==3) ans += (head.y+l+1);
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

