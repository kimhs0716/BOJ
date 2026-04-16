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

template <typename T>
ostream& operator<<(ostream &os, vector<T> &arr) {
    for (auto &x: arr) os<<x<<' ';
    return os;
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

ll dr[] = {0, 1, 0, -1};
ll dc[] = {1, 0, -1, 0};

void solve(ll tc){
    ll i, j;
    ll n, m; cin>>n>>m;
    map<string, ll> cnt;
    for (i=0;i<n;i++) {
        string s; cin>>s;
        cnt[s] = 0;
    }
    while (m--) {
        string s, d; ll x;
        cin>>s>>x>>d;
        cnt[s]+=x;
    }
    ll max_val=0;
    vector<string> ans;
    for (auto &it: cnt) {
        if (it.second>max_val) {
            max_val = it.second;
            ans.clear();
        }
        if (it.second==max_val) ans.push_back(it.first);
    }
    cout<<"VOTE "<<tc<<": ";
    if (ans.size()==1) cout<<"THE WINNER IS "<<ans[0]<<' '<<cnt[ans[0]]<<endl;
    else cout<<"THERE IS A DILEMMA\n";
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