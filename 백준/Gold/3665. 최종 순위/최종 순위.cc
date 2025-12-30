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
    ll n; cin>>n;
    vl arr(n); cin>>arr;
    set<pll> inv;
    ll m; cin>>m;
    while (m--) {
        ll x, y; cin>>x>>y;
        inv.insert({x, y});
    }
    vvl adj(n);
    for (i=0;i<n;i++) {
        for (j=i+1;j<n;j++) {
            if (inv.contains({arr[i], arr[j]}) || inv.contains({arr[j], arr[i]}))
                adj[arr[j]-1].push_back(arr[i]-1);
            else adj[arr[i]-1].push_back(arr[j]-1);
        }
    }
    // for (auto &x: adj) cout<<x<<endl;
    vl st, ans;
    bool a=false, b=false;
    for (i=0;i<n;i++) if (adj[i].size()==0) st.push_back(i);
    for (i=0;i<n;i++) {
        if (st.size()==0) {
            b = true;
            break;
        }
        else if (st.size()!=1) {
            a = true;
        }
        ll cur = st.back();
        st.pop_back();
        ans.push_back(cur);
        for (j=0;j<n;j++) {
            auto it = find(adj[j].begin(), adj[j].end(), cur);
            if (it != adj[j].end()) {
                adj[j].erase(it);
                if (adj[j].size()==0) st.push_back(j);
            }
        }
    }
    if (b) cout<<"IMPOSSIBLE\n";
    else if (a) cout<<"?\n";
    else {
        reverse(ans.begin(), ans.end());
        for (auto x: ans) cout<<x+1<<' '; cout<<endl;
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
