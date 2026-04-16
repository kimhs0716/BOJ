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

struct F {
    ll ja,mo;
    F(ll _ja=0, ll _mo=1) : ja(_ja), mo(_mo) {
        if (mo<0) ja=-ja,mo=-mo;
        ll g=gcd(ja, mo);
        ja/=g; mo/=g;
    }
    F operator+(const F o)const {
        return {ja*o.mo+o.ja*mo, mo*o.mo};
    }
    F operator-(const F o)const {
        return {ja*o.mo-o.ja*mo, mo*o.mo};
    }
    F operator*(const F o)const {
        return {ja*o.ja, mo*o.mo};
    }
    F operator/(const F o)const {
        return {ja*o.mo, mo*o.ja};
    }
    bool operator==(const F o)const {
        return ja==o.ja && mo==o.mo;
    }
    bool operator<(const F& o)const {
        return ja*o.mo<o.ja*mo;
    }
};

void solve(ll testcase) {
    ll i, j;
    ll n, idx=1;
    while(true) {
        cin>>n;
        if(!n) break;
        F ans;
        while(n--) {
            string s; cin>>s;
            stringstream ss(s);
            ll w=0, a=0, b=1;
            if(count(s.begin(), s.end(), ',')) {
                ss>>w;
                ss.ignore();
            }
            ss>>a;
            if(count(s.begin(), s.end(), '/')) {
                ss.ignore();
                ss>>b;
            }
            // cout<<F(w*b+a, b).ja<<'/'<<F(w*b+a, b).mo<<endl;
            ans = ans + F(w*b+a, b);
        }
        cout<<"Test "<<idx++<<": ";
        if(ans.ja >= ans.mo) {
            if(ans.ja%ans.mo==0) {
                cout<<ans.ja/ans.mo<<endl;
                continue;
            }
            cout<<ans.ja/ans.mo<<',';
            ans.ja %= ans.mo;
        }
        if(ans.mo!=1) cout<<ans.ja<<'/'<<ans.mo<<endl;
        else cout<<ans.ja<<endl;
    }
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