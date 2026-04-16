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
    ll n; cin>>n;
    vl arr(n+1), vis(n+1, -1);
    for (i=1;i<=n;i++) {
        cin>>arr[i];
        arr[i] += i;
    }
    // cout<<arr<<endl;
    function<ll(ll)> dfs = [&arr, &vis, &dfs](ll cur) {
        ll nxt = arr[cur];
        if (nxt == cur) return vis[cur] = cur;
        vis[cur] = 0;
        if (vis[nxt] == -1) return vis[cur] = dfs(nxt);
        if (vis[nxt] == 0) return vis[cur] = INF;
        return vis[cur] = vis[nxt];
    };
    for (i=1;i<=n;i++) if (vis[i]==-1) {
        vis[i] = 0;
        dfs(i);
    }
    // cout<<vis<<endl;
    swap(arr, vis);
    ll time = 1;
    queue<ll> q;
    vis.assign(n+1, 0);
    q.push(1);
    vis[1] = 0;
    while (q.size()) {
        ll sz = q.size();
        while (sz--) {
            ll cur = q.front(); q.pop();
            for (i=1;i<=6;i++) {
                if (cur+i>=n || arr[cur+i]!=INF && arr[cur+i]>=n) {
                    cout<<time<<endl;
                    return;
                }
                ll nxt = arr[cur+i];
                if (arr[cur+i]==INF || vis[nxt]) continue;
                vis[nxt] = time;
                q.push(nxt);
            }
        }
        time++;
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

