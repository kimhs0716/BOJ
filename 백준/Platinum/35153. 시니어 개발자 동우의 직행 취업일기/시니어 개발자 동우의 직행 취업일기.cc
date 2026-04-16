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

tlll f(ll n) {
    ll s = max((ll)powl(n, 0.5)/2-100, 1LL);
    for (ll b=s;b<n;b++) {
        for (ll c=s;c<=b;c++) {
            if (b*c>n) break;
            if ((n-b*c)%(b+c)==0) {
                ll a = (n-b*c)/(b+c);
                if (a+b+c+4>1000000) continue;
                return {a, b, c};
            }
        }
    }
    return {-1, -1, -1};
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    if (n==1) {
        cout<<"2\n1 2\n";
    }
    else if (n==2) {
        cout<<"5\n1 2\n2 3\n3 4\n3 5\n";
    }
    else {
        auto [a, b, c] = f(n);
        cout<<a+b+c+4<<endl;
        cout<<"1 2\n1 3\n1 4\n";
        for (i=1;i<=a;i++) cout<<"2 "<<4+i<<endl;
        for (i=1;i<=b;i++) cout<<"3 "<<4+a+i<<endl;
        for (i=1;i<=c;i++) cout<<"4 "<<4+a+b+i<<endl;
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
