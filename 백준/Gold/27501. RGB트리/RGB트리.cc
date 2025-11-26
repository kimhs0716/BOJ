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
constexpr ll INF = 1e15;

void preprocess() {
    ll i, j;
}

void solve(ll tc) {
    ll i, j;
    ll n; cin>>n;
    vvl adj(n);
    for (i=0;i<n-1;i++) {
        ll u, v; cin>>u>>v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vl R(n), G(n), B(n);
    for (i=0;i<n;i++) {
        cin>>R[i]>>G[i]>>B[i];
    }
    vector<tlll> best(n);
    vector<array<vl, 3>> prev(n);
    for (i=0;i<n;i++) {
        prev[i][0] = vl(adj[i].size());
        prev[i][1] = vl(adj[i].size());
        prev[i][2] = vl(adj[i].size());
    }
    function<void(ll, ll)> dfs = [&](ll cur, ll par) {
        best[cur][0] = R[cur];
        best[cur][1] = G[cur];
        best[cur][2] = B[cur];
        for (ll c = 0; c < 3; c++) {
            for (ll i=0;i<adj[cur].size();i++) {
                ll nxt = adj[cur][i];
                if (nxt == par) continue;
                if (c==0) dfs(nxt, cur);
                ll best_cc = -1;
                ll best_val = 0;
                for (ll cc=0; cc<3; cc++) {
                    if (c==cc) continue;
                    if (best[nxt][cc] > best_val) {
                        best_cc = cc;
                        best_val = best[nxt][cc];
                    }
                }
                best[cur][c] += best_val;
                prev[cur][c][i] = best_cc;
            }
        }
    };

    dfs(0, -1);

    ll root = 0;
    ll root_col = 0;
    if (best[root][1] > best[root][root_col]) root_col = 1;
    if (best[root][2] > best[root][root_col]) root_col = 2;

    ll ans = best[root][root_col];
    vl col(n);
    col[root] = root_col;

    vector<pll> st;
    st.push_back({root, -1});

    while (!st.empty()) {
        auto [cur, par] = st.back();
        st.pop_back();

        ll c = col[cur];

        for (i = 0; i < adj[cur].size(); i++) {
            ll nxt = adj[cur][i];
            if (nxt == par) continue;

            ll cc = prev[cur][c][i];
            col[nxt] = cc;
            st.push_back({nxt, cur});
        }
    }

    string s(n, 'R');
    for (i = 0; i < n; i++) {
        if (col[i] == 0) s[i] = 'R';
        else if (col[i] == 1) s[i] = 'G';
        else s[i] = 'B';
    }

    cout << ans << endl;
    cout << s << endl;
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

