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

void solve(ll tc){
    ll i, j;
    constexpr ld epsilon = 1e-6;
    ll n; cin>>n;
    vector<pair<ld, ld>> arr(n);
    for (i=0;i<n;i++) {
        cin>>arr[i].first;
        arr[i].second = 1;
    }
    while (arr.size()>1) {
        vector<pair<ld, ld>> temp;
        for (i=0;i<arr.size()-1;i++) {
            auto [a, b] = arr[i];
            auto [c, d] = arr[i+1];
            ld x=-1, y=-1;
            if (fabsl(b-d)<epsilon) {
                x = (a+c)/2;
                y = b + sqrtl(4 - (x-a)*(x-a));
            }
            else {
                ld p = (c-a) / (b-d);
                ld q = (a*a-c*c+b*b-d*d) / (2*(b-d));
                ld A = 1+p*p;
                ld B = 2*(p*q - p*b - a);
                ld C = a*a+(q-b)*(q-b)-4;
                ld x1 = (-B+sqrtl(B*B-4*A*C)) / (2*A);
                ld x2 = (-B-sqrtl(B*B-4*A*C)) / (2*A);
                ld y1 = p*x1 + q;
                ld y2 = p*x2 + q;
                if (y1<y2) {
                    x = x2;
                    y = y2;
                }
                else {
                    x = x1;
                    y = y1;
                }
            }
            temp.push_back({x, y});
        }
        swap(temp, arr);
        // for (auto &[x, y] : arr) cout<<x<<' '<<y<<endl; cout<<endl;
    }
    cout<<setprecision(4)<<fixed;
    cout<<arr[0].first<<' ';
    cout<<arr[0].second<<endl;
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
