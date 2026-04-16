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
    while (true) {
        string s; cin>>s;
        if (s=="#") break;
        cin>>s;
        vector<char> found(10), ans;
        if (s[0]==s[1]) {
            if (!found[s[0]-'0']) ans.push_back(s[0]);
            found[s[0]-'0']=1;
        }
        if (s[1]==s[2]) {
            if (!found[s[1]-'0']) ans.push_back(s[1]);
            found[s[1]-'0']=1;
        }
        if (s[2]==s[3]) {
            if (!found[s[2]-'0']) ans.push_back(s[2]);
            found[s[2]-'0']=1;
        }
        if (ans.size()) cout<<ans[0]<<' '<<ans[0]<<" glued";
        for (i=1;i<ans.size();i++) {
            cout<<" and "<<ans[i]<<' '<<ans[i]<<" glued";
        }
        cin>>s;
        if (ans.size()) cout<<endl;
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