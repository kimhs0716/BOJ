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
constexpr ld eps = 1e-8;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    cout<<"Scenario #"<<tc<<":\n";
    ll n, c1, c2; cin>>n>>c1>>c2;
    vl arr(n); cin>>arr;
    ll ans = INF;
    for (ll mask=0;mask<(1LL<<n);mask++) {
        multiset<ll> a, b;
        for (i=0;i<n;i++) {
            if ((mask>>i)&1) a.insert(-arr[i]);
            else b.insert(-arr[i]);
        }
        if (a.size() && c1<-*a.begin()) continue;
        if (b.size() && c2<-*b.begin()) continue;
        // for (auto x : a) cout<<-x<<' '; cout<<endl;
        // for (auto x : b) cout<<-x<<' '; cout<<endl;
        ll cur = 0;
        while (a.size() || b.size()) {
            vl temp;
            ll s = 0;
            for (auto x : a) if (s-x <= c1) {
                temp.push_back(x);
                s -= x;
            }
            while (temp.size()) {
                auto it = a.find(temp.back());
                a.erase(it);
                temp.pop_back();
            }
            s = 0;
            for (auto x : b) if (s-x <= c2) {
                temp.push_back(x);
                s -= x;
            }
            while (temp.size()) {
                auto it = b.find(temp.back());
                b.erase(it);
                temp.pop_back();
            }
            cur++;
        }
        ans = min(ans, cur);
        // cout<<cur<<endl;
    }
    cout<<ans<<endl;
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    cin >> testcase;
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
        if (i != testcase) cout<<endl;
    }
}
