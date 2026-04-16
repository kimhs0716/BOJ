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

struct Fraction {
    ll ja, mo;
    Fraction(ll j=1, ll m=1) : ja(j), mo(m) {
        simplify();
    }
    void simplify() {
        if (mo<0) {
            mo=-mo, ja=-ja;
        }
        ll g = gcd(ja, mo);
        ja/=g, mo/=g;
    }
    Fraction operator*(Fraction rhs) {
        Fraction ret(ja*rhs.ja, mo*rhs.mo);
        ret.simplify();
        return ret;
    }
    Fraction operator+(Fraction rhs) {
        Fraction ret(ja*rhs.mo + mo*rhs.ja, mo*rhs.mo);
        ret.simplify();
        return ret;
    }
    Fraction operator-(Fraction rhs) {
        Fraction ret(ja*rhs.mo - mo*rhs.ja, mo*rhs.mo);
        ret.simplify();
        return ret;
    }
};

void solve(ll testcase) {
    ll i, j, k;
    ll p, q, r; cin>>p>>q>>r;
    Fraction x(3*p-2*q+r, 2*(p+r));
    Fraction y(p+2*q-r, 2*(p+r));
    if (x.ja<=0 || x.ja>=x.mo || y.ja<=0 || y.ja>=y.mo) {
        cout<<"-1\n";
        return;
    }
    cout<<x.ja<<'/'<<x.mo<<' ';
    cout<<y.ja<<'/'<<y.mo<<endl;;
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