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
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j, k;
}

struct Point {
    ll x, y;
};

bool operator<(Point a, Point b) {
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

istream& operator>>(istream &is, Point &p) {
    return is>>p.x>>p.y;
}

ld dist(Point &a, Point &b) {
    return sqrtl((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    ld ans=0;
    set<pair<Point, Point>> s;
    for (i=0;i<n;i++) {
        vector<Point> p(3);
        cin>>p;
        sort(p.begin(), p.end());
        Point a, b;

        a=p[0], b=p[1];
        if (s.contains({a, b})) ans -= dist(a, b);
        else {
            ans += dist(a, b);
            s.insert({a, b});
        }

        a=p[1], b=p[2];
        if (s.contains({a, b})) ans -= dist(a, b);
        else {
            ans += dist(a, b);
            s.insert({a, b});
        }

        a=p[0], b=p[2];
        if (s.contains({a, b})) ans -= dist(a, b);
        else {
            ans += dist(a, b);
            s.insert({a, b});
        }
    }
    cout<<fixed<<setprecision(10);
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