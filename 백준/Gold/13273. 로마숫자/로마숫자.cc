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

// constexpr ll MOD = 1e9+7;
constexpr ll MOD = 998'244'353;
constexpr ll INF = 1e18;

vector<pair<string,ll>> r2a{
        {"M", 1000}, {"MC", 900}, {"D", 500}, {"DC", 400},
        {"C", 100}, {"CX", 90}, {"L", 50}, {"LX", 40},
        {"X", 10}, {"XI", 9}, {"V", 5}, {"VI", 4},
        {"I", 1}
};
ll foo(string &s) {
    ll ret=0;
    reverse(s.begin(), s.end());
    while (s.size()) {
        for (auto &[p, v] : r2a) {
            bool flag=false;
            while (s.ends_with(p)) {
                for (auto ch : p) s.pop_back();
                ret += v;
                flag=true;
            }
            if (flag) break;
        }
    }
    return ret;
}
string bar(ll n) {
    string ret;
    while (n>=1000) {
        ret += "M";
        n -= 1000;
    }
    if (n/100 == 9) {
        ret += "CM";
        n -= 900;
    }
    if (n/100 >= 5) {
        ret += "D";
        n -= 500;
    }
    if (n/100 == 4) {
        ret += "CD";
        n -= 400;
    }
    while (n>=100) {
        ret += "C";
        n -= 100;
    }
    if (n/10 == 9) {
        ret += "XC";
        n -= 90;
    }
    if (n/10 >= 5) {
        ret += "L";
        n -= 50;
    }
    if (n/10 == 4) {
        ret += "XL";
        n -= 40;
    }
    while (n>=10) {
        ret += "X";
        n -= 10;
    }
    if (n == 9) {
        ret += "IX";
        n -= 9;
    }
    if (n >= 5) {
        ret += "V";
        n -= 5;
    }
    if (n == 4) {
        ret += "IV";
        n -= 4;
    }
    while (n>=1) {
        ret += "I";
        n -= 1;
    }
    return ret;
}

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    string s; cin>>s;
    if (isdigit(s[0])) {
        cout<<bar(stoi(s))<<endl;
    }
    else {
        cout<<foo(s)<<endl;
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

