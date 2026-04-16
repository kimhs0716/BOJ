// #include <bits/stdc++.h>
// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target ("avx,avx2,fma")
//
// using namespace std;
// using ll = long long;
// using vl = vector<ll>;
// using vvl = vector<vl>;
// using pll = pair<ll, ll>;
// using ld = long double;
// using vd = vector<ld>;
// using ull = unsigned long long;
// using vp = vector<pll>;
// using vvp = vector<vp>;
// using tlll = array<ll, 3>;
//
// #define endl '\n'
//
// void setup() {
// #ifdef KIMHS
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #else
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
// #endif
// }
//
// template <typename T>
// istream& operator>>(istream &is, vector<T> &arr) {
//     for (auto &x: arr) is>>x;
//     return is;
// }
//
// template <typename T>
// ostream& operator<<(ostream &os, vector<T> &arr) {
//     if (arr.size()==0) return os<<"()";
//     os<<'(';
//     for (ll i=0;i<arr.size()-1;i++) os<<arr[i]<<' ';
//     if (arr.size()) os<<arr.back();
//     return os<<')';
// }
//
// constexpr ll MOD = 1e9+7;
// // constexpr ll MOD = 998'244'353;
// constexpr ll INF = 2e18;
//
// void preprocess() {
//     ll i, j, k;
// }
//
// //Usage: vl distance = dijk(V, start, adj);
// //O(ElogV)
// vl dijk(ll n, ll s, vector<vector<pll>>& adj){
//     const ll INF = 1e18;
//     vl dis(n,INF);
//     vector<bool> visit(n, false);
//     priority_queue<pll, vector<pll>, greater<pll> > q; // pair(dist, v)
//     dis[s] = 0;
//     q.push({dis[s], s});
//     while (!q.empty()){
//         while (!q.empty() && visit[q.top().second]) q.pop();
//         if (q.empty()) break;
//         ll next=q.top().second; q.pop();
//         visit[next]=1;
//         for (ll i=0;i<adj[next].size();++i)
//             if (dis[adj[next][i].first] > dis[next] + adj[next][i].second){
//                 dis[adj[next][i].first] = dis[next] + adj[next][i].second;
//                 q.push({dis[adj[next][i].first], adj[next][i].first});}}
//     for(ll i=0;i<n;i++) if(dis[i]==INF) dis[i]=-1;
//     return dis;
// }
//
// void solve(ll testcase) {
//     ll i, j, k;
//     ll n, m; cin>>n>>m;
//     n *= m;
//     ll x, y; cin>>x>>y;
//     --x; --y;
//     x = x*m+y;
//     ll a, b, c; cin>>a>>b>>c;
//     vl arr(n); cin>>arr;
//     ll g=0, gi=-1;
//     for (i=0;i<n;i++) if (g<arr[i]) {
//         g=arr[i];
//         gi=i;
//     }
//     vvp adj(n);
//     auto add_edge = [&adj, &arr, a, b, c](ll u, ll v) -> void {
//         ll h1 = arr[u], h2 = arr[v];
//         if (llabs(h1-h2)>c) return;
//         ll t=1;
//         if (h1<h2) t=(h2-h1)*a;
//         if (h1>h2) t=(h1-h2)*b;
//         adj[u].push_back({v, t});
//     };
//     for (i=0;i<n;i++) {
//         if (i-m>=0) add_edge(i, i-m);
//         if (i%m!=0) add_edge(i, i-1);
//         if (i%m!=m-1) add_edge(i, i+1);
//         if (i+m<n) add_edge(i, i+m);
//     }
//     // cout<<arr<<endl;
//     // for (i=0;i<n;i++) {
//     //     for (auto [u, w] : adj[i]) cout<<"("<<u<<','<<w<<','<<arr[u]<<") ";
//     //     cout<<endl;
//     // }
//     vl dist = dijk(n, x, adj);
//     cout<<dist[gi]<<endl;
// }
//
//
// int main() {
//     setup();
//     preprocess();
//
//     ll testcase = 1;
//     // cin >> testcase;
//     for (ll i = 1; i <= testcase; i++) {
//         solve(i);
//     }
// }

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
ostream& operator<<(ostream &os, vector<T> &arr) {
    if (arr.size()==0) return os<<"()";
    os<<'(';
    for (ll i=0;i<arr.size()-1;i++) os<<arr[i]<<' ';
    if (arr.size()) os<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>k>>n;
    vl arr(n); cin>>arr;
    vl s(arr);
    sort(s.begin(), s.end());
    ll idx=0;
    for (auto x: arr) {
        if (x==s[idx]) idx++;
    }
    cout<<k<<' '<<n-idx<<endl;
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