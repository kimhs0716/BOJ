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

bool check(vector<array<ll, 3>> &arr, vl &mask) {
    for (ll i=0;i<6;i++) if (arr[mask[i]][0] != arr[mask[(i+1)%6]][2]) return false;
    return true;
}

ll score(vector<array<ll, 3>> &arr, vl &mask) {
    ll sum=0;
    for (ll i=0;i<6;i++) sum+=arr[mask[i]][1];
    return sum;
}

void rotate(array<ll, 3> &t) {
    swap(t[0], t[1]);
    swap(t[2], t[1]);
}

void solve(ll testcase) {
    ll i, j;
    while (true) {
        vector<array<ll, 3>> arr(6);
        for (auto &x: arr) cin>>x[0]>>x[1]>>x[2];
        ll ans=-1;
        vl mask {0, 1, 2, 3, 4, 5};
        do {
            for (i=0;i<729;i++) {
                if (check(arr, mask))
                    ans = max(ans, score(arr, mask));
                rotate(arr[0]);
                if (i%3==0) rotate(arr[1]);
                if (i%9==0) rotate(arr[2]);
                if (i%27==0) rotate(arr[3]);
                if (i%81==0) rotate(arr[4]);
                if (i%243==0) rotate(arr[5]);
            }
        } while (next_permutation(mask.begin(), mask.end()));
        if (ans==-1) cout<<"none\n";
        else cout<<ans<<endl;
        char nxt; cin>>nxt;
        if (nxt=='$') break;
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