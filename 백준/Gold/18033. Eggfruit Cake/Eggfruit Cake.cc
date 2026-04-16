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

void solve(ll testcase) {
    ll i, j;
    string s; cin>>s;
    ll n = s.size();
    ll k; cin>>k;
    ll ans = n*k;
    vl ps;
    ll cur=0;
    if (count(s.begin(), s.end(), 'E')==0) {
        cout<<"0\n";
        return;
    }
    for (i=0;i<n;i++) {
        if (s[i]=='P') cur++;
        else {
            if (cur) ps.push_back(cur);
            cur=0;
        }
    }
    if (cur) ps.push_back(cur);
    if (s[0]=='P' && s.back()=='P' && ps.size()>=2) {
        ps[0] += ps.back();
        ps.pop_back();
    }
    for (ll x: ps) {
        ll m = min(x, k);
        ans -= m * (x+1) - m * (m+1) / 2;
    }
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