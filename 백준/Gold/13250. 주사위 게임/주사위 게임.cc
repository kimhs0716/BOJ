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

using vl = vector<ll>;
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
                    ret[i][j] %= MOD;
                }
            }
        }
        return ret;
    }
    Matrix operator*(const ll k) const {
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

int main() {
    FASTIO;
    _init();

    ll n; cin >> n;

    vector<ld> cache(n + 1);
    cache[1] = 1;
    for (ll i = 2; i <= n; i++) {
        cache[i] = 1;
        if (i >= 6) cache[i] += cache[i - 6] / 6;
        if (i >= 5) cache[i] += cache[i - 5] / 6;
        if (i >= 4) cache[i] += cache[i - 4] / 6;
        if (i >= 3) cache[i] += cache[i - 3] / 6;
        if (i >= 2) cache[i] += cache[i - 2] / 6;
        if (i >= 1) cache[i] += cache[i - 1] / 6;
    }

    cout.precision(10);
    cout << fixed;
    cout << cache[n] << endl;

    return 0;
}
