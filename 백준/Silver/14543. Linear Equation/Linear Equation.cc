#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

using namespace std;
// using ll = long long;
using ll = __int128;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
// using ld = long double;
using ld = __float128;
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

template <typename T>
ostream& operator<<(ostream &os, vector<T> &arr) {
    for (auto &x: arr) os<<x<<' ';
    return os;
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
    cout<<fixed;
    cout.precision(6);
}

ostream &operator<<(ostream &os, ld x) {
    return os<<(long double)x;
}

istream &operator>>(istream &os, ll &x) {
    string s; cin>>s;
    x = 0;
    for (char i : s) {
        if (i=='x') continue;
        x=(x<<3)+(x<<1);
        x+=i-48;
    }
    return os;
}

ostream &operator<<(ostream &os, ll x) {
    string s;
    if (x==0) return os<<'0';
    if (x<0) os<<'-', x=-x;
    ll t=x;
    while (t) {
        s.push_back(t%10 + '0');
        t/=10;
    }
    reverse(s.begin(), s.end());
    return os<<s;
}

void solve(ll tc){
    ll i, j;
    ll a, b, c;
    char d;
    cin>>a>>d>>b>>d>>c;
    c-=b;
    cout<<"Equation "<<tc<<endl;
    // cout<<a<<' '<<c<<endl;
    if (a==0) {
        if (c==0) cout<<"More than one solution.\n";
        else cout<<"No solution.\n";
    }
    else {
        ll ans=1000000*c/a;
        cout<<"x = ";
        if (ans<0) cout<<'-', ans=-ans;
        cout<<(ans/1000000)<<'.';
        cout<<setw(6)<<setfill('0');
        cout<<ans%1000000<<endl;
    }
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    cin >> testcase;
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
        if (i!=testcase) cout<<endl;
    }
}