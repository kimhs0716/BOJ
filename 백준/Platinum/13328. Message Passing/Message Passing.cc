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
    for (ll i=0;i<arr.size()-1;i++) cout<<arr[i]<<' ';
    if (arr.size()) cout<<arr.back();
    return os<<')';
}

// constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll MOD = 31991;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j, k;
}

struct Matrix {
    ll r, c;
    vvl arr;
    Matrix(ll r, ll c) : r(r), c(c), arr(r, vl(c)) {}
    Matrix mul(const Matrix &o) const {
        assert(c==o.r);
        Matrix ret(r, o.c);
        for (ll i=0;i<r;i++) {
            for (ll j=0;j<o.c;j++) {
                for (ll k=0;k<c;k++) {
                    ret.arr[i][j] += arr[i][k] * o.arr[k][j] % MOD;
                    if (ret.arr[i][j]>=MOD) ret.arr[i][j] -= MOD;
                }
            }
        }
        return ret;
    }
};

Matrix I(ll n) {
    Matrix ret(n, n);
    for (ll i=0;i<n;i++) ret.arr[i][i] = 1;
    return ret;
}

Matrix __pow(Matrix m, ll k) {
    assert(m.r == m.c);
    Matrix ret = I(m.r);
    while (k) {
        if (k&1) ret = ret.mul(m);
        m = m.mul(m);
        k >>= 1;
    }
    return ret;
}

void solve(ll testcase) {
    ll i, j, k;
    ll d, t; cin>>d>>t;
    vl a(d); a[0] = 1;
    for (i=1;i<d;i++) {
        for (j=0;j<i;j++) a[i] = (a[i]+a[j])%MOD;
    }
    if (t<=d-1) {
        cout<<a[t]<<endl;
        return;
    }
    reverse(a.begin(), a.end());
    Matrix f(d, d);
    for (i=0;i<d;i++) f.arr[0][i] = 1;
    for (i=0;i<d-1;i++) f.arr[i+1][i] = 1;
    Matrix m(d, 1);
    for (i=0;i<d;i++) m.arr[i][0] = a[i];
    cout<<__pow(f, t-d+1).mul(m).arr[0][0]<<endl;
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