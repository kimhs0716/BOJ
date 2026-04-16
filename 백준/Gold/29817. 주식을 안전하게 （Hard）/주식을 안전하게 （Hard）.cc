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

struct Matrix {
    ll r, c;
    vvl arr;
    Matrix(ll r, ll c) : r(r), c(c), arr(r, vl(c)) {}
    Matrix mul(const Matrix &o) const {
        assert(c == o.r);
        Matrix ret(r, o.c);
        for (ll i=0;i<r;i++) {
            for (ll j=0;j<o.c;j++) {
                for (ll k=0;k<c;k++) {
                    ret.arr[i][j] += arr[i][k] * o.arr[k][j] % MOD;
                    if (ret.arr[i][j]>=MOD) ret.arr[i][j]-=MOD;
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
    ll p, c; cin >> p >> c >> k;
    c %= MOD;

    vl first(p-1);
    ll cur; cin >> cur;
    for (i=0;i<p-1;i++) {
        ll x; cin >> x;
        first[p-i-2] = (x - cur) % MOD;
        if (first[p-i-2] < 0) first[p-i-2] += MOD;
        cur = x;
    }

    Matrix a(p, p), m(p, 1);
    for (i=0;i<p-1;i++) m.arr[i][0] = first[i];
    m.arr[p-1][0] = 0;

    ll pw = c;
    for (j=0;j<p-1;j++) {
        a.arr[0][j] = (MOD - pw) % MOD;
        pw = (pw * c) % MOD;
    }
    for (i=1;i<p-1;i++) a.arr[i][i-1] = 1;
    for (j=0;j<p-1;j++) a.arr[p-1][j] = a.arr[0][j];
    a.arr[p-1][p-1] = 1;

    ll exp = k - (p - 1);
    Matrix res = __pow(a, exp).mul(m);

    ll Sk  = res.arr[p-1][0] % MOD;
    ll Mp1 = (cur % MOD + MOD) % MOD;
    ll ans = (Mp1 + Sk) % MOD;
    cout << ans << '\n';
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