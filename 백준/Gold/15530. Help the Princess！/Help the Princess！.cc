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

void solve(ll testcase) {
    ll i, j, k;
    ll r, c; cin>>r>>c;
    pll start, goal;
    vector<pll> soldiers;
    vvl arr(r, vl(c));
    vvl vis(r, vl(c));
    for (i=0;i<r;i++) {
        string s; cin>>s;
        for (j=0;j<c;j++) {
            if (s[j]=='@') start = {i, j};
            if (s[j]=='$') soldiers.emplace_back(i, j);
            if (s[j]=='%') goal = {i, j};
            arr[i][j] = s[j]=='$' || s[j]=='#';
        }
    }
    // for (i=0;i<r;i++) {
    //     for (j=0;j<c;j++) cout<<arr[i][j]<<' ';
    //     cout<<endl;
    // }
    queue<pll> q;
    q.push(start);
    vis[start.first][start.second]=1;
    while (true) {
        vector<pll> new_soldiers;
        for (auto &[sr, sc]: soldiers) {
            for (i=0;i<4;i++) {
                ll nr = sr+dr[i];
                ll nc = sc+dc[i];
                if (nr<0 || nr>=r) continue;
                if (nc<0 || nc>=c) continue;
                if (arr[nr][nc]==1) continue;
                arr[nr][nc]=1;
                new_soldiers.emplace_back(nr, nc);
            }
        }
        swap(soldiers, new_soldiers);
        ll sz=q.size();
        while (sz--) {
            auto &[cr, cc] = q.front(); q.pop();
            for (i=0;i<4;i++) {
                ll nr = cr+dr[i];
                ll nc = cc+dc[i];
                if (nr<0 || nr>=r) continue;
                if (nc<0 || nc>=c) continue;
                if (arr[nr][nc]==1) continue;
                if (vis[nr][nc]) continue;
                if (goal == make_pair(nr, nc)) {
                    cout<<"Yes\n";
                    return;
                }
                vis[nr][nc]=1;
                q.emplace(nr, nc);
            }
        }
        if (q.empty()) break;
    }
    cout<<"No\n";
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