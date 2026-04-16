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
constexpr ll INF = 1e18;

void preprocess() {
    ll i, j, k;
}

bool isprime(ll x) {
    if (x<2) return false;
    if (x==2) return true;
    if (x%2==0) return false;
    for (ll i=3;i*i<=x;i+=2)
        if (x%i==0) return false;
    return true;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n;
    while (true) {
        cin>>n;
        if (!n) break;
        cout<<setw(7)<<setfill(' ');
        cout<<n<<' ';
        while (n>=10 && !isprime(n)) {
            ll t=0;
            while (n) {
                t += n%10;
                n /= 10;
            }
            n = t;
        }
        cout<<setw(7)<<setfill(' ');
        if (!isprime(n)) cout<<"none"<<endl;
        else cout<<n<<endl;
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

