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

struct Mat {
    ll r, c;
    vvl arr;
    Mat(ll _r, ll _c) : r(_r), c(_c), arr(r, vl(c)) {}
    Mat operator*(Mat &rhs) {
        assert(c==rhs.r);
        Mat res(r, rhs.c);
        for (ll i=0;i<r;i++) {
            for (ll j=0;j<rhs.c;j++) {
                ll sum=0;
                for (ll k=0;k<c;k++) {
                    sum = (sum+arr[i][k]*rhs.arr[k][j])%MOD;
                }
                res.arr[i][j] = sum;
            }
        }
        return res;
    }
};

Mat I(ll n) {
    Mat ret(n, n);
    for (ll i=0;i<n;i++)
        ret.arr[i][i] = 1;
    return ret;
}

Mat pow(Mat m, ll k) {
    assert(m.r == m.c);
    Mat ret = I(m.r);
    while (k) {
        if (k&1) ret=ret*m;
        m=m*m;
        k>>=1;
    }
    return ret;
}

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    Mat a(3, 3), b(3, 1);
    for (i=0;i<3;i++)
        for (j=0;j<3;j++)
            a.arr[i][j] = 1;
    a.arr[0][0] = 0;
    a.arr[1][1] = 0;
    b.arr[0][0] = b.arr[1][0] = b.arr[2][0] = 1;

    Mat res = pow(a, n-1) * b;
    // cout<<res.arr[0][0]<<' ';
    // cout<<res.arr[1][0]<<' ';
    // cout<<res.arr[2][0]<<endl;
    cout<<(res.arr[0][0] + res.arr[1][0] + res.arr[2][0])%MOD<<endl;
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

