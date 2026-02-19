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

vvp moves = {
    {},
    {{-1, -1}, {-1, 1}}, // pawn_up
    {{1, -1}, {1, 1}}, // pawn_down
    {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}}, // knight
    {}, // bishop
    {}, // rook
    {}, // queen
    {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}}, // king
};

void solve(ll tc){
    ll i, j;
    /*
     * 0: blank
     *
     * 1: pawn_up
     * 2: pawn_down
     * 3: knight
     * 4: bishop
     * 5: rook
     * 6: queen
     * 7: king
     */
    string s;
    while (cin>>s) {
        vvl arr(8, vl(8));
        ll idx = 0;
        s.push_back('/');
        for (i=0;i<8;i++) {
            j = 0;
            while (true) {
                char ch = s[idx];
                if (ch=='/') {
                    idx++;
                    break;
                }
                else if (ch=='P') arr[i][j] = 1;
                else if (ch=='p') arr[i][j] = 2;
                else if (ch=='n' || ch=='N') arr[i][j] = 3;
                else if (ch=='b' || ch=='B') arr[i][j] = 4;
                else if (ch=='r' || ch=='R') arr[i][j] = 5;
                else if (ch=='q' || ch=='Q') arr[i][j] = 6;
                else if (ch=='k' || ch=='K') arr[i][j] = 7;
                else if (ch!='0') {
                    s[idx]--;
                    idx--;
                }
                else j--;
                j++;
                idx++;
            }
        }
        function check = [&arr](ll r, ll c) {
            if (arr[r][c]==4 || arr[r][c]==6) { // bishop, queen
                ll i, j;
                i=r-1, j=c-1;
                while (i>=0 && j>=0) {
                    if (arr[i][j]>0) break;
                    arr[i][j] = -1;
                    --i; --j;
                }
                i=r-1, j=c+1;
                while (i>=0 && j<8) {
                    if (arr[i][j]>0) break;
                    arr[i][j] = -1;
                    --i; ++j;
                }
                i=r+1, j=c-1;
                while (i<8 && j>=0) {
                    if (arr[i][j]>0) break;
                    arr[i][j] = -1;
                    ++i; --j;
                }
                i=r+1, j=c+1;
                while (i<8 && j<8) {
                    if (arr[i][j]>0) break;
                    arr[i][j] = -1;
                    ++i; ++j;
                }
            }
            if (arr[r][c]==5 || arr[r][c]==6) { // rook, queen
                ll i, j;
                i=r-1, j=c;
                while (i>=0) {
                    if (arr[i][j]>0) break;
                    arr[i][j] = -1;
                    --i;
                }
                i=r, j=c+1;
                while (j<8) {
                    if (arr[i][j]>0) break;
                    arr[i][j] = -1;
                    ++j;
                }
                i=r, j=c-1;
                while (j>=0) {
                    if (arr[i][j]>0) break;
                    arr[i][j] = -1;
                    --j;
                }
                i=r+1, j=c;
                while (i<8) {
                    if (arr[i][j]>0) break;
                    arr[i][j] = -1;
                    ++i;
                }
            }
            if (moves[arr[r][c]].size()) {
                for (auto [dr, dc] : moves[arr[r][c]]) {
                    ll nr=r+dr, nc=c+dc;
                    if (nr<0 || nr>=8) continue;
                    if (nc<0 || nc>=8) continue;
                    if (arr[nr][nc]) continue;
                    arr[nr][nc] = -1;
                }
            }
        };
        for (i=0;i<8;i++) {
            for (j=0;j<8;j++) {
                if (arr[i][j]>0) check(i, j);
            }
        }
        ll ans = 0;
        for (i=0;i<8;i++) {
            for (j=0;j<8;j++) {
                // if (arr[i][j]!=-1) cout<<arr[i][j]<<' ';
                // else cout<<'X'<<' ';
                if (arr[i][j]==0) ans++;
            }
            // cout<<endl;
        }
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
