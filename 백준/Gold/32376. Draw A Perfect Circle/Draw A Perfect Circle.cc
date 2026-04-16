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
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;
// constexpr ll MAX = 10'000'000;

void preprocess() {
    ll i, j, k;
}

struct Point {
    ll x, y;
    ll dist2;
    Point (ll _x, ll _y) : x(_x), y(_y), dist2(x*x+y*y) {}
    Point () : x(0), y(0), dist2(x*x+y*y) {}
};

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n>>k;
    vector<Point> arr;
    arr.reserve(n);
    for (i=0;i<n;i++) {
        ll x, y; cin>>x>>y;
        arr.emplace_back(x, y);
    }
    sort(arr.begin(), arr.end(), [](const Point &a, const Point &b) {
        return a.dist2<b.dist2;
    });
    // for (auto &[x, y, d]: arr) cout<<d<<' '; cout<<endl;
    ll ans=0;
    ll left=0, right=0;
    while (right<n) {
        while (right<n) {
            ll a = arr[left].dist2, b = arr[right].dist2;
            if (a+b-k*k > 0 && (a+b-k*k)*(a+b-k*k) > 4*a*b) {
                right--;
                break;
            }
            right++;
        }
        if (right==n) right--;
        if (right-left+1 > ans) ans=right-left+1;
        ll cur=arr[left].dist2;
        right++;
        while (left<right && arr[left].dist2==cur) left++;
    }
    cout<<fixed<<setprecision(10);
    cout<<(ld)ans*100/n<<endl;
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