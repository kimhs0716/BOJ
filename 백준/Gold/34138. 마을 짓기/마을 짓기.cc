#include <bits/stdc++.h>
// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target ("avx,avx2,fma")

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using ld = long double;
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
    os<<'(';
    for (auto &x: arr) os<<x<<' ';
    return os<<')';
}

constexpr ll MOD = 1e9+7;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j;
}

void solve(ll testcase) {
    ll i, j;
    ll r, c; cin>>r>>c;
    vvl arr(r, vl(c));
    for (i=0;i<r;i++) {
        string s; cin>>s;
        for (j=0;j<c;j++) {
            arr[i][j] = (s[j]=='X');
        }
    }
    ll k = min(r, c);
    vl ans(k);
    vp cand;
    for (i=0;i<r;i++) {
        for (j=0;j<c;j++) {
            if (arr[i][j]) cand.push_back({i, j});
        }
    }
    ans[0] = cand.size();

    ll sz = 2;
    while (--k) {
        vp new_cand;
        for (auto [rr, cc]: cand) {
            if (rr==r-1 || cc==c-1) continue;
            if (arr[rr+1][cc+1] == 0) continue;
            bool flag = true;
            for (i=0;i<sz-1;i++) {
                if (arr[rr+1][cc-i]==1) flag=false;
                if (arr[rr-i][cc+1]==1) flag=false;
                if (!flag) break;
            }
            if (!flag) continue;
            new_cand.push_back({rr+1, cc+1});
        }
        swap(cand, new_cand);
        ans[sz-1] = cand.size();
        sz++;
    }
    for (auto x: ans) cout<<x<<endl;
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