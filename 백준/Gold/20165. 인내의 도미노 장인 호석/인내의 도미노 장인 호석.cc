#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx,avx2,fma")

#define endl '\n'
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;

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

ll f(vvl &arr, vvl &fell, ll r, ll c, ll dir) {
    ll rr=arr.size(), cc=arr[0].size();
    ll i, ret=0;
    if (dir==0) {
        ll bound = max(0LL, r-arr[r][c]+1);
        for (i=r;i>=bound;i--) {
            if (fell[i][c]) continue;
            fell[i][c] = 1;
            bound = max(0LL, min(bound, i-arr[i][c]+1));
            ret++;
        }
    }
    if (dir==1) {
        ll bound = min(cc-1, c+arr[r][c]-1);
        for (i=c;i<=bound;i++) {
            if (fell[r][i]) continue;
            fell[r][i] = 1;
            bound = min(cc-1, max(bound, i+arr[r][i]-1));
            ret++;
        }
    }
    if (dir==2) {
        ll bound = min(rr-1, r+arr[r][c]-1);
        for (i=r;i<=bound;i++) {
            if (fell[i][c]) continue;
            fell[i][c] = 1;
            bound = min(rr-1, max(bound, i+arr[i][c]-1));
            ret++;
        }
    }
    if (dir==3) {
        ll bound = max(0LL, c-arr[r][c]+1);
        for (i=c;i>=bound;i--) {
            if (fell[r][i]) continue;
            fell[r][i] = 1;
            bound = max(0LL, min(bound, i-arr[r][i]+1));
            ret++;
        }
    }
    return ret;
}

void solve(ll tc) {
    ll i, j;
    ll r, c, q; cin>>r>>c>>q;
    vvl arr(r, vl(c)), fell(r, vl(c));
    cin>>arr;
    ll score=0;
    while (q--) {
        char dir;
        cin>>r>>c>>dir;
        --r, --c;
        if (dir=='N') {
            score += f(arr, fell, r, c, 0);
        }
        if (dir=='E') {
            score += f(arr, fell, r, c, 1);
        }
        if (dir=='S') {
            score += f(arr, fell, r, c, 2);
        }
        if (dir=='W') {
            score += f(arr, fell, r, c, 3);
        }

        cin>>r>>c;
        fell[r-1][c-1]=0;
        // cout<<score<<endl;
        // for (auto &x: fell) {
        //     for (auto &y: x) cout<<(y?'F':'S')<<' ';
        //     cout<<endl;
        // }
        // cout<<endl;
    }
    cout<<score<<endl;
    for (auto &x: fell) {
        for (auto &y: x) cout<<(y?'F':'S')<<' ';
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