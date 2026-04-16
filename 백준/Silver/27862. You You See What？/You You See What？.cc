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
ostream& operator<<(ostream &os, vector<T> &arr) {
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) cout<<arr[i]<<' ';
    if (arr.size()) cout<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j, k;
}

string to_lower(string &s) {
    string ret;
    for (char ch: s) {
        if (ch<'a' || ch>'z') ch = ch-'A'+'a';
        ret += ch;
    }
    return ret;
}

void solve(ll testcase) {
    ll i, j, k;
    string s; cin>>s;
    vl arr;
    ll l=0, r=0;
    map<string, ll> to_id;
    map<ll, string> from_id;
    while (r<s.size()) {
        if (s[r]=='!') {
            string t = s.substr(l, r-l);
            l=r+1;
            string lo = to_lower(t);
            // cout<<t<<' '<<lo<<endl;
            if (!to_id.contains(lo)) {
                from_id[to_id.size()] = t;
                to_id[lo] = to_id.size();
            }
            arr.push_back(to_id[lo]);
        }
        r++;
    }
    string last = s.substr(l, r-l);
    // cout<<arr<<endl;
    // cout<<last<<endl;
    vl st;
    for (auto &x : arr) {
        if (st.empty()) st.push_back(x);
        else if (st.back()==x) continue;
        else if (st.size()>1 && st[st.size()-2]==x) st.pop_back();
        else st.push_back(x);
    }
    for (auto x: st) {
        cout<<from_id[x]<<'!';
    }
    cout<<last<<endl;
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