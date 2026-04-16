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
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

struct Matrix {
    ll r, c;
    vvl arr;
    Matrix(ll _r, ll _c) : r(_r), c(_c), arr(r, vl(c)) {}
    Matrix operator*(const Matrix &rhs) const {
        assert(c == rhs.r);
        Matrix ret(r, rhs.c);
        for (ll i=0;i<r;i++) {
            for (ll j=0;j<rhs.c;j++) {
                ll s=0;
                for (ll k=0;k<c;k++) {
                    s += arr[i][k] * rhs.arr[k][j] % MOD;
                    if (s >= MOD) s -= MOD;
                }
                ret.arr[i][j] = s;
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
        if (k&1) ret=ret*m;
        m=m*m;
        k>>=1;
    }
    return ret;
}

void solve(ll testcase) {
    ll i, j;
    ll n, m; cin>>n>>m;
    Matrix a(n, 1), b(n, n);
    a.arr[0][0] = 1;
    while (m--) {
        ll u, v; cin>>u>>v;
        --u, --v;
        b.arr[u][v] = 1;
        b.arr[v][u] = 1;
    }
    ll d; cin>>d;
    a = __pow(b, d) * a;
    cout<<a.arr[0][0]<<endl;
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