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

struct F {
    ll ja,mo;
    F(ll _ja=0, ll _mo=1) : ja(_ja), mo(_mo) {
        if (mo<0) ja=-ja,mo=-mo;
        ll g=gcd(ja, mo);
        ja/=g; mo/=g;
    }
    F operator+(const F& o)const {
        return {ja*o.mo+o.ja*mo, mo*o.mo};
    }
    F operator-(const F& o)const {
        return {ja*o.mo-o.ja*mo, mo*o.mo};
    }
    F operator*(const F& o)const {
        return {ja*o.ja, mo*o.mo};
    }
    F operator/(const F& o)const {
        return {ja*o.mo, mo*o.ja};
    }
    bool operator==(const F& o)const {
        return ja==o.ja && mo==o.mo;
    }
    bool operator<(const F& o)const {
        return ja*o.mo<o.ja*mo;
    }
};


void preprocess() {
    ll i, j;

}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    F ans(arr[n-1]);
    for (i=n-2;i>=0;i--) {
        ans = F(arr[i]) + F(1) / ans;
        // cout<<ans.ja<<'/'<<ans.mo<<endl;
    }
    ans = F(1) - F(1) / ans;
    cout<<ans.ja<<' '<<ans.mo<<endl;
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