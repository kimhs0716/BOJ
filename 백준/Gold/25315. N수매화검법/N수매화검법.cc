#include <bits/stdc++.h>

#include <utility>
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

void preprocess() {
    ll i, j;
}

struct Point {
    ll x, y;
    Point operator-(const Point rhs) const {
        return {x-rhs.x, y-rhs.y};
    }
};

struct Line {
    Point p1, p2;
};

ll outer(const Point a, const Point b) {
    return a.x*b.y - a.y*b.x;
}

ll diff(ll a, ll b) {
    if (a<b) return -1;
    if (a==b) return 0;
    return 1;
}

ll CCW(const Point a, const Point b, const Point c) {
    return diff(outer(b-a, c-a), 0);
}

bool cross(const Line a, const Line b) {
    if (CCW(a.p1, a.p2, b.p1) * CCW(a.p1, a.p2, b.p2) == 1) return false;
    if (CCW(b.p1, b.p2, a.p1) * CCW(b.p1, b.p2, a.p2) == 1) return false;
    return true;
}

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    vector<pair<Line, ll>> arr(n);
    for (i=0;i<n;i++) {
        cin>>arr[i].first.p1.x;
        cin>>arr[i].first.p1.y;
        cin>>arr[i].first.p2.x;
        cin>>arr[i].first.p2.y;
        cin>>arr[i].second;
    }
    sort(arr.begin(), arr.end(), [](const auto a, const auto b) {
        return a.second > b.second;
    });
    ll ans = 0;
    for (i=0;i<n;i++) {
        for (j=0;j<i;j++) {
            if (cross(arr[i].first, arr[j].first))
                ans += arr[i].second;
            // cout<<i<<' '<<j<<' '<<cross(arr[i].first, arr[j].first)<<endl;
        }
        ans += arr[i].second;
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
