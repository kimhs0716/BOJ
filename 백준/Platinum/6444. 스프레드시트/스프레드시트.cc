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

vector<string> split(string &s, char sep) {
    vector<string> ret;
    ll prev = 0;
    for (ll i=0;i<s.size();i++) {
        if (s[i]==sep) {
            ret.push_back(s.substr(prev, i-prev));
            prev = i+1;
        }
    }
    if (prev < s.size()) ret.push_back(s.substr(prev));
    return ret;
}

pll to_idx(string &s) {
    ll c=0, i=0;
    while ('A'<=s[i] && s[i]<='Z') {
        c *= 26;
        c += s[i]-'A'+1;
        i++;
    }
    return {stoll(s.substr(i))-1, c-1};
}

void solve(ll tc){
    ll i, j;
    ll c, r; cin>>c>>r;
    vector arr(r, vector(c, pair<ll, vp>(INF, vp())));
    for (i=0;i<r;i++) {
        for (j=0;j<c;j++) {
            string s; cin>>s;
            if (s[0]=='=') {
                s = s.substr(1);
                for (auto x : split(s, '+'))
                    arr[i][j].second.push_back(to_idx(x));
            }
            else {
                arr[i][j].first = stoll(s);
            }
        }
    }
    function<ll(ll, ll)> find = [&arr, &find](ll r, ll c) {
        if (arr[r][c].first != INF) return arr[r][c].first;
        ll s = 0;
        for (auto &[pr, pc] : arr[r][c].second) {
            s += find(pr, pc);
        }
        return arr[r][c].first = s;
    };
    for (i=0;i<r;i++) {
        for (j=0;j<c;j++) cout<<find(i, j)<<' ';
        cout<<endl;
    }
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    cin >> testcase;
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
    }
}
