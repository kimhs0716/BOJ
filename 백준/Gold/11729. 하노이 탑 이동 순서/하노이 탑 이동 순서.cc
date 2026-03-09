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

void hanoi(ll n, ll a, ll b, ll c) {
    // move n discs from a to c
    // if (!n) return;
    // hanoi(n-1, a, c, b);
    // cout<<a<<' '<<c<<endl;
    // hanoi(n-1, b, a, c);
    vector<array<ll, 5>> st;
    st.push_back({n, a, b, c, 1});
    while (st.size()) {
        auto [n, a, b, c, s] = st.back();
        st.pop_back();
        if (!n) continue;
        if (s==1) {
            st.push_back({n, a, b, c, 2});
            st.push_back({n-1, a, c, b, 1});
        }
        else if (s==2) {
            cout<<a<<' '<<c<<endl;
            st.push_back({n-1, b, a, c, 1});
        }
    }
}

void solve(ll tc){
    ll i, j;
    ll n; cin>>n;
    cout<<(1LL<<n)-1<<endl;
    hanoi(n, 1, 2, 3);
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
