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

// constexpr ll MOD = 1e9+7;
constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e15;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll n, k; cin>>n>>k;
    ll a, b, c, d; cin>>a>>b>>c>>d;
    priority_queue<ll> pq[4];
    while (n--) {
        char ch; ll x;
        cin>>ch>>x;
        pq[ch-'A'].push(x);
    }
    while (k--) {
        pll t = {-1, -1};
        if (pq[0].size()) {
            ll dv = pq[0].top() * b*c*d;
            t = max(t, {dv, 0});
        }
        if (pq[1].size()) {
            ll dv = pq[1].top() * a*c*d;
            t = max(t, {dv, 1});
        }
        if (pq[2].size()) {
            ll dv = pq[2].top() * a*b*d;
            t = max(t, {dv, 2});
        }
        if (pq[3].size()) {
            ll dv = pq[3].top() * a*b*c;
            t = max(t, {dv, 3});
        }
        if (t.second==0) a += pq[t.second].top();
        if (t.second==1) b += pq[t.second].top();
        if (t.second==2) c += pq[t.second].top();
        if (t.second==3) d += pq[t.second].top();
        cout<<(char)(t.second+'A')<<' '<<pq[t.second].top()<<endl;
        pq[t.second].pop();
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
