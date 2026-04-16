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
constexpr ll INF = (ll)1e18+1;

void preprocess() {
    ll i, j;
}

void solve(ll tc){
    ll i, j;
    ll r, c; cin>>r>>c;
    vp ans;
    if (r==1) {
        string s; cin>>s;
        for (i=0;i<c;i++) {
            if (s[i]=='X') {
                if (i+1<c && s[i+1]=='X') {
                    ans.push_back({i+1, i+2});
                    i++;
                }
                else ans.push_back({i+1, -1});
            }
        }
    }
    else {
        vvl arr(c, vl(r));
        for (i=0;i<r;i++) {
            string s; cin>>s;
            for (j=0;j<c;j++) {
                arr[j][i] = s[j]=='X';
            }
        }
        for (i=0;i<c;i++) {
            for (j=0;j<r;j++) {
                if (arr[i][j]) {
                    if (j+1<r && arr[i][j+1]) {
                        ans.push_back({i*r+j+1, i*r+j+2});
                        j++;
                    }
                    else ans.push_back({i*r+j+1, -1});
                }
            }
        }
    }
    cout<<ans.size()<<endl;
    for (auto [x, y] : ans) {
        if (y==-1) cout<<"1 "<<x<<endl;
        else cout<<"2 "<<x<<' '<<y<<endl;
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
