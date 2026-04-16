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
constexpr ll INF = 1e18;

void preprocess() {
    ll i, j, k;
}

struct Node {
    Node *ch[4] = {0, 0, 0, 0};
    ll color = -1;
    ull H = -1;
    ull hash() {
        if (color != -1) return (color ? 4567123 : 7654321);
        if (H==-1) {
            H = 1234567;
            for (ll i=0;i<4;i++) {
                H *= ch[i]->hash();
                H ^= (H<<17);
                H += ch[i]->hash();
                H ^= (H>>5);
                H *= ch[i]->hash();
                H ^= (H<<13);
            }
        }
        return H;
    }
};

void solve(ll testcase) {
    ll i, j, k;
    ll r, c; cin>>r>>c;
    ll m = max(r, c);
    if (__builtin_popcountll(m) != 1)
        m = 1LL << (64 - __builtin_clzll(m));
    vvl arr(m, vl(m));
    for (i=0;i<r;i++) {
        string s; cin>>s;
        for (j=0;j<c;j++)
            arr[i][j] = s[j]-'0';
    }
    function<Node*(ll, ll, ll)> f = [&arr, &f](ll r, ll c, ll sz) -> Node* {
        bool flag = true;
        for (ll i=0;i<sz;i++) {
            for (ll j=0;j<sz;j++)
                if (arr[r+i][c+j] != arr[r][c]) {
                    flag = false;
                    break;
                }
            if (!flag) break;
        }
        if (flag) return new Node {{0, 0, 0, 0}, arr[r][c]};
        Node *ret = new Node;
        sz >>= 1;
        ret->ch[0] = f(r, c, sz);
        ret->ch[1] = f(r, c+sz, sz);
        ret->ch[2] = f(r+sz, c, sz);
        ret->ch[3] = f(r+sz, c+sz, sz);
        return ret;
    };
    Node *root = f(0, 0, m);
    ll ans1=0, ans2=0;
    set<ull> hs;
    function<ll(Node*)> cnt1 = [&cnt1](Node *cur) -> ll {
        if (cur->color==-1)
            return 1 + cnt1(cur->ch[0]) + cnt1(cur->ch[1]) + cnt1(cur->ch[2]) + cnt1(cur->ch[3]);
        return 1;
    };
    function<ll(Node*)> cnt2 = [&hs, &cnt2](Node *cur) -> ll {
        ll H = cur->hash();
        if (cur->color==-1) {
            if (hs.contains(H)) return 0;
            hs.insert(H);
            return 1 + cnt2(cur->ch[0]) + cnt2(cur->ch[1]) + cnt2(cur->ch[2]) + cnt2(cur->ch[3]);
        }
        return 1;
    };
    cout<<cnt1(root)<<' '<<cnt2(root)<<endl;
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

