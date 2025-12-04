#include <bits/stdc++.h>
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

bool wins(ll x, ll y, vvl &arr) {
    ll cnt = 0;
    for (auto &a : arr) {
        if (a[x]>a[y]) cnt--;
        else cnt++;
    }
    return cnt > 0;
}

void solve(ll tc) {
    ll i, j;
    tc = 0;
    while (true) {
        ll b, c; cin>>b>>c;
        if (!b) break;
        vvl arr(b, vl(c));
        for (i=0;i<b;i++) {
            for (j=0;j<c;j++) {
                ll x; cin>>x;
                arr[i][x] = j;
            }
        }
        ll cand = 0;
        for (i=1;i<c;i++) {
            if (wins(i, cand, arr)) cand = i;
        }
        bool flag = true;
        for (i=0;i<c;i++) {
            if (i==cand) continue;
            if (!wins(cand, i, arr)) {
                flag = false;
                break;
            }
        }
        cout<<"Case "<<++tc<<": ";
        if (flag) {
            cout<<cand<<endl;
        }
        else {
            cout<<"No Condorcet winner\n";
        }
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

