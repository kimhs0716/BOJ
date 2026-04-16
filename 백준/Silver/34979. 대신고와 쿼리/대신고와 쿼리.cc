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

void solve(ll tc) {
    ll i, j;
    ll n, q; cin>>n>>q;
    vl arr(n<<2);
    while (q--) {
        ll a, b, c;
        cin>>a>>b;
        --b;
        if (a==1) {
            cin>>c;
            --c;
            arr[b*n+c]++;
            if (b!=0) arr[(b-1)*n+c]++;
            if (b!=3) arr[(b+1)*n+c]++;
            if (c!=0) arr[b*n+c-1]++;
            if (c!=n-1) arr[b*n+c+1]++;
        }
        else {
            ll ans = 0;
            for (i=1;i<n;i++) {
                if (arr[n*b+i] > arr[n*b+ans]) ans = i;
            }
            cout<<ans+1<<endl;
        }
    }
    ll ans = 0;
    for (i=1;i<4*n;i++) {
        if (arr[i] > arr[ans]) ans = i;
    }
    cout<<(ans/n)+1<<' '<<(ans%n)+1<<endl;
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

