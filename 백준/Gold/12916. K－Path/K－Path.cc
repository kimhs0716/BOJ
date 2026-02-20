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
constexpr ll INF = (ll)1e18+1;

void preprocess() {
    ll i, j;
}

struct Mat {
    ll r, c;
    vvl arr;
    Mat(ll r, ll c) : r(r), c(c), arr(r, vl(c)) {}
    Mat operator*(const Mat &rhs) const {
        assert(c == rhs.r);
        Mat ret(r, rhs.c);
        for (ll i=0;i<r;i++) {
            for (ll j=0;j<rhs.c;j++) {
                for (ll k=0;k<c;k++) {
                    ret.arr[i][j] += arr[i][k] * rhs.arr[k][j] % MOD;
                    ret.arr[i][j] %= MOD;
                }
            }
        }
        return ret;
    }
    Mat operator^(ll k) const {
        assert(r == c);
        Mat n(r, r);
        Mat ret(r, r);
        for (ll i=0;i<r;i++) {
            n.arr[i] = arr[i];
            ret.arr[i][i] = 1;
        }
        while (k) {
            if (k&1) ret = ret * n;
            n = n * n;
            k >>= 1;
        }
        return ret;
    }
};

ostream& operator<<(ostream &os, const Mat &m) {
    for (ll i=0;i<m.r;i++) {
        for (ll j=0;j<m.c;j++) os<<m.arr[i][j]<<' ';
        os<<endl;
    }
    return os;
}

void solve(ll tc){
    ll i, j;
    ll n, k; cin>>n>>k;
    Mat m(n, n); cin>>m.arr;
    m = m^k;
    ll ans = 0;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            ans = (ans+m.arr[i][j]) % MOD;
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
