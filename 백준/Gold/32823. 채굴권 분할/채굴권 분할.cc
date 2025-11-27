#include <bits/stdc++.h>
#pragma GCC optimize ("O0,unroll-loops")
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

struct Point {
    ld x, y;
    Point operator-(const Point& o) const {
        return Point{ x-o.x, y-o.y };
    }
};

struct Segment {
    Point p1, p2;
};

constexpr ld eps = 1e-9;
inline ll diff(ld lhs, ld rhs) {
    if (lhs-eps<rhs && rhs<lhs+eps) return 0;
    return lhs<rhs ? -1 : 1;
}

ld outer(const Point a, const Point b) {
    return a.x*b.y-a.y*b.x;
}

ll ccw(const Point a, const Point b, const Point c) {
    return diff(outer(b-a, c-a), 0);
}

bool seg_seg(const Segment a, const Segment b) {
    return (ccw(a.p1, a.p2, b.p1)*ccw(a.p1, a.p2, b.p2)<=0) && (ccw(b.p1, b.p2, a.p1)*ccw(b.p1, b.p2, a.p2)<=0);
}

void preprocess() {
    ll i, j;
}

constexpr ld PI = 3.141592653589793238;
void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    vector<Segment> arr(n);
    for (i=0;i<n;i++) {
        ll t;
        cin>>t;
        Point p1 = {1000.0L*cos(t*PI/1800), 1000.0L*sin(t*PI/1800)};
        cin>>t;
        Point p2 = {1000.0L*cos(t*PI/1800), 1000.0L*sin(t*PI/1800)};
        arr[i] = {p1, p2};
    }
    ll t, r;
    cin>>t>>r;
    Point p1 = {r*cos(t*PI/1800), r*sin(t*PI/1800)};
    cin>>t>>r;
    Point p2 = {r*cos(t*PI/1800), r*sin(t*PI/1800)};
    ll cnt = 0;
    // cout<<'('<<p1.x<<", "<<p1.y<<") "<<'('<<p2.x<<", "<<p2.y<<") "<<endl;
    for (auto s: arr) {
        // cout<<'('<<s.p1.x<<", "<<s.p1.y<<") "<<'('<<s.p2.x<<", "<<s.p2.y<<") "<<endl;
        if (seg_seg(s, {p1, p2})) cnt++;
    }
    if (cnt&1) cout<<"NO\n";
    else cout<<"YES\n";
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

