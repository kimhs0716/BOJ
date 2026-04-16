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

ll dist(pll a, pll b) {
    return llabs(a.first-b.first) + llabs(a.second-b.second);
}

void solve(ll testcase) {
    ll i, j, k;
    ll n; cin>>n>>k;
    vp items(n);
    for (auto &[x, y] : items) cin>>x>>y;
    pll goal, org={0, 0};
    cin>>goal.first>>goal.second;
    set<pll> s, e;
    if (k==1) {
        if (dist(org, goal)==1) cout<<"1\n";
        else cout<<"-1\n";
    }
    else if (k==2) {
        if (dist(org, goal)<=2) cout<<dist(org, goal)<<endl;
        else {
            for (auto [dx, dy] : items) {
                if (dx==goal.first && dy==goal.second) {
                    cout<<"2\n";
                    return;
                }
            }
            cout<<"-1\n";
        }
    }
    else if (k==3) {
        ll ans = INF;
        if (dist(org, goal)<=3) ans = dist(org, goal);
        for (auto [dx, dy] : items) {
            if (dist(goal, {dx, dy})<=1) {
                ans = min(ans, 2+dist(goal, {dx, dy}));
            }
        }
        if (ans==INF) ans = -1;
        cout<<ans<<endl;
    }
    else if (k==4) {
        ll ans = INF;
        if (dist(org, goal)<=4) ans = dist(org, goal);
        for (auto [dx, dy] : items) {
            if (dist(goal, {dx, dy})<=2) {
                ans = min(ans, 2+dist(goal, {dx, dy}));
            }
        }
        for (auto [dx, dy] : items) {
            s.insert({dx, dy});
            e.insert({goal.first-dx, goal.second-dy});
        }
        for (auto [x, y] : s) {
            if (e.contains({x, y})) ans = min(ans, 4LL);
        }
        if (ans==INF) ans = -1;
        cout<<ans<<endl;
    }
    else {
        ll ans = INF;
        if (dist(org, goal)<=5) ans = dist(org, goal);
        for (auto [dx, dy] : items) {
            if (dist(goal, {dx, dy})<=3) {
                ans = min(ans, 2+dist(goal, {dx, dy}));
            }
        }
        for (auto [dx, dy] : items) {
            s.insert({dx, dy});
            e.insert({goal.first-dx, goal.second-dy});
        }
        for (auto [x, y] : s) {
            if (e.contains({x, y})) ans = min(ans, 4LL);
            if (e.contains({x+1, y})) ans = min(ans, 5LL);
            if (e.contains({x-1, y})) ans = min(ans, 5LL);
            if (e.contains({x, y+1})) ans = min(ans, 5LL);
            if (e.contains({x, y-1})) ans = min(ans, 5LL);
        }
        if (ans==INF) ans = -1;
        cout<<ans<<endl;
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