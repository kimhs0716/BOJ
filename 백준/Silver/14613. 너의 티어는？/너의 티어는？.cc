//#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <utility> // pair, move
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <cassert>
#include <functional> // function
#include <numeric>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifdef KIMHS
    freopen("boj.in", "r", stdin);
    freopen("boj.out", "w", stdout);
#endif // KIMHS
}

using namespace std;

using ll = long long int;
using ld = long double;

using vl = vector<ld>;
using pll = pair<ll, ll>;
using tlll = tuple<ll, ll, ll>;

constexpr ll MOD = 1'000'000'007;
constexpr ll INF = 2147483647;

struct Matrix {
    ll r, c;
    vector<vl> arr;
    Matrix (ll r, ll c) : r(r), c(c), arr(r, vl(c)) {}
    Matrix operator*(const Matrix &other) const {
        Matrix ret(r, other.c);
        for (ll i = 0; i < r; ++i) {
            for (ll j = 0; j < other.c; ++j) {
                for (ll k = 0; k < c; ++k) {
                    ret[i][j] += arr[i][k] * other[k][j];
                    // ret[i][j] %= MOD;
                }
            }
        }
        return ret;
    }
    Matrix operator*(const ld k) const {
        Matrix ret = *this;
        for (ll i = 0; i < r; ++i) {
            for (ll j = 0; j < c; ++j) {
                ret[i][j] = arr[i][j] * k;
            }
        }
        return ret;
    }
    static Matrix I(ll n) {
        Matrix ret(n, n);
        for (ll i = 0; i < n; ++i) ret[i][i] = 1;
        return ret;
    }
    Matrix operator^(ll k) const {
        Matrix ret = I(r), cur = *this;
        while (k) {
            if (k & 1) ret = ret * cur;
            cur = cur * cur;
            k >>= 1;
        }
        return ret;
    }
    vl& operator[](const ll idx) {
        return arr[idx];
    }
    const vl& operator[](const ll idx) const {
        return arr[idx];
    }
};

istream& operator>>(istream& is, Matrix& mat) {
    for (ll i = 0; i < mat.r; ++i) {
        for (ll j = 0; j < mat.c; ++j) {
            is >> mat[i][j];
        }
    }
    return is;
}

ostream& operator<<(ostream& os, const Matrix& mat) {
    for (ll i = 0; i < mat.r; ++i) {
        for (ll j = 0; j < mat.c; ++j) {
            os << mat[i][j];
            if (j + 1 < mat.c) os << ' ';
        }
        os << endl;
    }
    return os;
}

ld sum(const Matrix &m, ll s, ll e) {
    ld ret = 0;
    for (ll i = s; i < e; i++) {
        ret += m[i][0];
    }
    return ret;
}

int main() {
    FASTIO;
    _init();

    ld win, lose, draw; cin >> win >> lose >> draw;
    Matrix dp(50, 1);
    dp[20][0] = 1;

    Matrix a = Matrix::I(50) * draw;
    for (ll i = 0; i < 49; i++) {
        a[i][i + 1] = lose;
        a[i + 1][i] = win;
    }

    auto res = (a ^ 20) * dp;

    cout.precision(8);
    cout << fixed;
    cout << sum(res, 0, 10) << endl;
    cout << sum(res, 10, 20) << endl;
    cout << sum(res, 20, 30) << endl;
    cout << sum(res, 30, 40) << endl;
    cout << sum(res, 40, 50) << endl;

    return 0;
}
