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
    ll n; cin>>n;
    vl arr(n+1);
    for (i=1;i<=n;i++) {
        string s; cin>>s;
        ll cnt = 0;
        bool in_vowel = false;
        for (char ch: s) {
            bool is_vowel = (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
            if (is_vowel && !in_vowel) {
                cnt++;
                in_vowel = true;
            }
            else if (!is_vowel) {
                in_vowel = false;
            }
        }
        arr[i]=arr[i-1]+cnt;
    }
    ll m = arr[n];
    vl pos(m+1, -1);
    for (i=0;i<=n;i++) pos[arr[i]]=i;
    ll ans=0;
    for (i=1;i<=n;i++) {
        ll b=arr[i-1];
        if (b+17>m) break;
        ll i1=pos[b+5];
        ll i2=pos[b+12];
        ll i3=pos[b+17];
        if (i1>i-1 && i2>i1 && i3>i2) ans++;
    }

    cout<<ans<<endl;
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