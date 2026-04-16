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

void solve(ll testcase) {
    ll i, j, k;
    ll arr[251][251] = {0, };
    for (i=0;i<=250;i++) arr[0][i] = 1;
    for (i=1;i<=250;i++) {
        for (j=1;j<=i/2;j++) {
            if (i-2*j==0) arr[i][j]++;
            for (k=j;k<=i-2*j;k++)
                arr[i][j] += arr[i-2*j][k];
        }
        arr[i][i] = 1;
    }
    // for (i=1;i<=10;i++) {
    //     for (j=1;j<=10;j++) cout<<arr[i][j]<<' ';
    //     cout<<endl;
    // }
    ll n;
    while (true) {
        cin>>n;
        if (!n) break;
        ll ans=0;
        for (i=1;i<=n;i++) ans += arr[n][i];
        cout<<n<<' '<<ans<<endl;
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

