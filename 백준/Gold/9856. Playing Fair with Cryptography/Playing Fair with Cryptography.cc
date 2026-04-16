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
    for (ll i=0;i<arr.size()-1;i++) cout<<arr[i]<<' ';
    if (arr.size()) cout<<arr.back();
    return os<<')';
}

constexpr ll MOD = 1e9+7;
// constexpr ll MOD = 998'244'353;
constexpr ll INF = 2e18;

void preprocess() {
    ll i, j, k;
}

pll find(vvl &arr, vp &pos, ll a, ll b) {
    pll p1 = pos[a], p2 = pos[b];
    if (p1.first == p2.first) {
        return {arr[p1.first][(p1.second+1)%5], arr[p2.first][(p2.second+1)%5]};
    }
    if (p1.second == p2.second) {
        return {arr[(p1.first+1)%5][p1.second], arr[(p2.first+1)%5][p2.second]};
    }
    return {arr[p1.first][p2.second], arr[p2.first][p1.second]};
}

void solve(ll testcase) {
    ll i, j, k;
    string s; getline(cin, s);
    string key;
    for (auto ch: s) {
        if ('a'<=ch && ch<='z') key += (ch-'a'+'A');
        else if ('A'<=ch && ch<='Z') key += ch;
    }
    getline(cin, s);
    string plain;
    for (auto ch: s) {
        if ('a'<=ch && ch<='z') plain += (ch-'a'+'A');
        else if ('A'<=ch && ch<='Z') plain += ch;
    }
    // cout<<key<<endl;
    // cout<<plain<<endl;
    ll idx=0;
    vvl arr(5, vl(5));
    vp pos(26, {-1, -1});
    for (auto ch: key) {
        if (pos[ch-'A'].first!=-1) continue;
        pos[ch-'A']={idx/5, idx%5};
        arr[idx/5][idx%5]=ch-'A';
        idx++;
    }
    for (i=0;i<26;i++) {
        if (i=='J'-'A') continue;
        if (pos[i].first!=-1) continue;
        pos[i]={idx/5, idx%5};
        arr[idx/5][idx%5]=i;
        idx++;
    }

    // for (i=0;i<5;i++) {
    //     for (j=0;j<5;j++) cout<<(char)(arr[i][j]+'A')<<' ';
    //     cout<<endl;
    // }

    // cout<<pos[1].first<<' ';
    // cout<<pos[1].second<<endl;

    cout<<"Case "<<testcase<<": ";
    ll nxt=0;
    for (i=0;i<plain.size();i+=2) {
        if (i==plain.size()-1 || plain[i] == plain[i+1]) {
            if (plain[i]-'A' == nxt) nxt = (nxt+1)%26;
            if (nxt == 'J'-'A') nxt++;
            auto [a, b] = find(arr, pos, plain[i]-'A', nxt);
            cout<<(char)(a+'A');
            cout<<(char)(b+'A');
            i--;
            nxt = (nxt+1)%26;
            if (nxt == 'J'-'A') nxt++;
        }
        else {
            auto [a, b] = find(arr, pos, plain[i]-'A', plain[i+1]-'A');
            cout<<(char)(a+'A');
            cout<<(char)(b+'A');
        }
    }
    cout<<endl;
}

int main() {
    setup();
    preprocess();

    ll testcase = 1;
    cin >> testcase;
    cin.ignore();
    for (ll i = 1; i <= testcase; i++) {
        solve(i);
    }
}