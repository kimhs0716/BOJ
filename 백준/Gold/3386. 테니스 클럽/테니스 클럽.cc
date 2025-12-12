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

ll argmax(vp &arr) {
    ll i, mx=arr[0].first;
    for (i=0;i<arr.size();i++) {
        mx = max(arr[i].first, mx);
    }
    for (i=0;i<arr.size();i++)
        if (arr[i].first==mx) return i;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    vp arr(n);
    for (i=0;i<n;i++) {
        cin>>arr[i].first;
        arr[i].second = i;
    }
    vvl ans(n);
    for (i=0;i<n;i++) {
        ll idx = argmax(arr);
        ll cnt = arr[idx].first;
        arr[idx].first = 0;
        idx = arr[idx].second;
        if (cnt >= n-i) {
            cout<<"NO SCHEDULE\n";
            return;
        }
        sort(arr.rbegin(), arr.rend());
        for (j=0;j<cnt;j++) {
            if (arr[j].first==0) {
                cout<<"NO SCHEDULE\n";
                return;
            }
            arr[j].first--;
            ans[idx].push_back(arr[j].second+1);
            ans[arr[j].second].push_back(idx+1);
        }
    }
    for (i=0;i<n;i++)
        if (arr[i].first) {
            cout<<"NO SCHEDULE\n";
            return;
        }
    cout<<"SCHEDULE\n";
    for (i=0;i<n;i++) {
        sort(ans[i].begin(), ans[i].end());
        for (auto x: ans[i]) cout<<x<<' ';
        cout<<endl;
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

