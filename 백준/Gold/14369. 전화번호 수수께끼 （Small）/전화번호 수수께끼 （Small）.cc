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

vector<string> num = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR",
    "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

void solve(ll tc){
    ll i, j;
    cout<<"Case #"<<tc<<": ";
    string s; cin>>s;
    vl cnt(26);
    for (auto ch : s) cnt[ch-'A']++;
    ll len = s.size();
    string ans;
    function<bool()> bt = [&cnt, &ans, &len, &bt]() {
        bool ok = true;
        for (auto x : cnt) {
            if (x<0) return false;
            if (x) ok = false;
        }
        if (ok) return true;
        for (ll i=0;i<10;i++) {
            ans.push_back('0'+i);
            for (auto ch : num[i]) cnt[ch-'A']--;
            if (bt()) return true;
            for (auto ch : num[i]) cnt[ch-'A']++;
            ans.pop_back();

        }
        return false;
    };
    bt();
    cout<<ans<<endl;
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
