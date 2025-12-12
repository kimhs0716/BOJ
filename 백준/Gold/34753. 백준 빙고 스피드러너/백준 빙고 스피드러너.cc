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
    vvl arr(n, vl(n)); cin>>arr;
    priority_queue<pll, vp, greater<>> pq;
    vl time(2*n+2);
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) time[i] += arr[i][j];
    }
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) time[n+i] += arr[j][i];
    }
    for (i=0;i<n;i++) {
        time[2*n] += arr[i][i];
        time[2*n+1] += arr[i][n-i-1];
    }
    for (i=0;i<2*n+2;i++)
        pq.push({time[i], i});
    ll ans = 0;
    vl vis(2*n+2);
    for (ll k=0;k<2*n+2;k++) {
        auto [t, line] = pq.top(); pq.pop();
        if (vis[line] || t != time[line]) {
            k--;
            continue;
        }
        ans += time[line];
        if (line < n) {
            for (i=0;i<n;i++) {
                time[n+i] -= arr[line][i];
                pq.push({time[n+i], n+i});
                if (i==line) {
                    time[2*n] -= arr[line][i];
                    pq.push({time[2*n], 2*n});
                }
                if (i+line == n-1) {
                    time[2*n+1] -= arr[line][i];
                    pq.push({time[2*n+1], 2*n+1});
                }
                arr[line][i] = 0;
            }
        }
        else if (line < 2*n) {
            for (i=0;i<n;i++) {
                time[i] -= arr[i][line-n];
                pq.push({time[i], i});
                if (i==line-n) {
                    time[2*n] -= arr[i][line-n];
                    pq.push({time[2*n], 2*n});
                }
                if (i+line-n == n-1) {
                    time[2*n+1] -= arr[i][line-n];
                    pq.push({time[2*n+1], 2*n+1});
                }
                arr[i][line-n] = 0;
            }
        }
        else if (line == 2*n) {
            for (i=0;i<n;i++) {
                time[i] -= arr[i][i];
                time[i+n] -= arr[i][i];
                pq.push({time[i], i});
                pq.push({time[i+n], i+n});
                if (i+i==n-1) {
                    time[2*n+1] -= arr[i][i];
                    pq.push({time[2*n+1], 2*n+1});
                }
                arr[i][i] = 0;
            }
        }
        else {
            for (i=0;i<n;i++) {
                time[i] -= arr[i][n-i-1];
                time[n-i-1+n] -= arr[i][n-i-1];
                pq.push({time[i], i});
                pq.push({time[n-i-1+n], n-i-1+n});
                if (i+i==n-1) {
                    time[2*n] -= arr[i][n-i-1];
                    pq.push({time[2*n], 2*n});
                }
                arr[i][n-i-1] = 0;
            }
        }
        time[line] = 0;
        vis[line] = 1;
        // cout<<time<<endl;
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

