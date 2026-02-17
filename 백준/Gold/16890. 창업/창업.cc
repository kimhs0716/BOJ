#include <bits/stdc++.h>

#include <utility>
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

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    string s, t; cin>>s>>t;
    ll n = s.size();
    string ans(n, '?');
    ll l=0, r=n-1;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    multiset<char> a, b;
    for (i=0;i<n-n/2;i++) a.insert(s[i]);
    for (i=0;i<n/2;i++) b.insert(t[n-i-1]);
    for (i=0;i<n;i++) {
        char a_min = a.empty() ? 0 : *a.begin();
        char b_max = b.empty() ? 0 : *b.rbegin();
        if (i&1) {
            if (a_min < b_max) {
                auto it = prev(b.end());
                ans[l++] = *it;
                b.erase(it);
            }
            else {
                auto it = b.begin();
                ans[r--] = *it;
                b.erase(it);
            }
        }
        else {
            if (a_min < b_max) {
                auto it = a.begin();
                ans[l++] = *it;
                a.erase(it);
            }
            else {
                auto it = prev(a.end());
                ans[r--] = *it;
                a.erase(it);
            }
        }
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
