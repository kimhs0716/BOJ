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

struct Point {
    ll x, y;
    Point operator-(const Point rhs) const {
        return Point(x-rhs.x, y-rhs.y);
    }
    bool operator==(const Point rhs) const {
        return x==rhs.x && y==rhs.y;
    }
};

ll outer(const Point a, const Point b) {
    return a.x*b.y - a.y*b.x;
}

ll ccw(const Point a, const Point b, const Point c) {
    ll t = outer(c-b, a-b);
    if (t<0) return -1;
    if (t==0) return 0;
    return 1;
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e15;

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;

    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<ll> dis(0, n);

    vector<Point> pts(n);
    for (auto &[x, y] : pts) cin>>x>>y;
    for (ll iter=0; iter<10; iter++) {
        Point p1 = pts[dis(gen)];
        Point p2 = pts[dis(gen)];
        if (p1 == p2) {
            iter--;
            continue;
        }
        vl used(n);
        for (i=0;i<n;i++) {
            if (ccw(p1, p2, pts[i])==0) {
                used[i] = 1;
            }
        }
        if (accumulate(used.begin(), used.end(), 0LL) >= n-1) {
            cout<<"success\n";
            return;
        }
        p1 = p2 = {INF, INF};
        for (i=0;i<n;i++) {
            if (used[i]) continue;
            if (p1.x == INF) p1 = pts[i];
            else if (p2.x == INF) p2 = pts[i];
            else break;
        }
        for (i=0;i<n;i++) {
            if (used[i]) continue;
            if (ccw(p1, p2, pts[i])==0) {
                used[i] = 1;
            }
        }
        if (accumulate(used.begin(), used.end(), 0LL) == n) {
            cout<<"success\n";
            return;
        }
    }
    cout<<"failure\n";
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

