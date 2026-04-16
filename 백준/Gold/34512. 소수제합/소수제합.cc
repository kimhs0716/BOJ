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
    if (arr.size()==0) return os<<"()";
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) os<<arr[i]<<' ';
    if (arr.size()) os<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;
// constexpr ll MAX = 65536;

void preprocess() {
    ll i, j, k;
}

constexpr ll MAX = 5000000;
void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n;
    if (n<=2) cout<<"-1\n";
    else if (n==3) cout<<"2 5 29\n";
    else if (n==4) cout<<"2 2 3 17\n";
    else if (n==6) cout<<"2 2 3 3 3 5\n";
    else {
        ll two, three;
        if (n%3==0) two=3;
        else if (n%3==1) two=2;
        else two=1;
        three = (n-2*two)/3;
        while (three--) cout<<"2 2 2 ";
        while (two--) cout<<"3 3 ";
        cout<<endl;
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