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
    ll t; cin>>t;
    if (t==1) {
        ull n; cin>>n;
        vl arr;
        while (n) {
            arr.push_back(n&1);
            n>>=1;
        }
        arr.pop_back();
        reverse(arr.begin(), arr.end());
        ull p=1, q=1;
        for (auto x: arr) {
            if (x) p+=q;
            else q+=p;
        }
        cout<<"Case #"<<tc<<": "<<p<<' '<<q<<endl;
    }
    else {
        ull p, q; cin>>p>>q;
        vl arr;
        while (p!=1 || q!=1) {
            if (p<q) {
                q-=p;
                arr.push_back(0);
            }
            else {
                p-=q;
                arr.push_back(1);
            }
        }
        arr.push_back(1);
        ull n=0;
        for (i=arr.size()-1;i>=0;--i) {
            n<<=1;
            n|=arr[i];
        }
        cout<<"Case #"<<tc<<": "<<n<<endl;
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