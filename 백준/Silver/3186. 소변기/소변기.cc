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

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll k, l, n; cin>>k>>l>>n;
    string s; cin>>s;
    vl ans;
    ll state=0, ones=0, zeros=0;
    for (i=0;i<n;i++) {
        if (state==0) {
            if (s[i]=='1') {
                ones++;
                if (ones>=k) {
                    state=1;
                    zeros=0;
                }
            }
            else ones=0;
        }
        else {
            if (s[i]=='0') {
                zeros++;
                if (zeros>=l) {
                    ans.push_back(i+1);
                    state=0;
                    ones=0;
                }
            }
            else zeros=0;
        }
    }
    if (state) {
        ans.push_back(n+max(1LL, l-zeros));
    }
    if (ans.size()) {
        for (auto x: ans) cout<<x<<endl;
    }
    else cout<<"NIKAD\n";
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