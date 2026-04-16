//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <utility> // pair
#include <set>
#include <queue>
#include <stack>
#include <map>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifndef BOJ
    freopen("boj.in", "r", stdin);
    freopen("boj.out", "w", stdout);
#endif // BOJ
}

using namespace std;

using ll = long long int;
using vi = vector<ll>;
using pii = pair<int, int>;

constexpr ll MOD = 1e9 + 7;
constexpr ll MAX = 1'000'001;

ll pow(int a, int r) {
    ll res = 1;
    while (r--) res *= a;
    return res;
}

void solve(string& s, int n) {
    if (n == 0) {
        s.push_back('-');
        return;
    }
    solve(s, n - 1);
    int t = pow(3, n - 1);
    for (int i = 0; i < t; i++) {
        s.push_back(' ');
    }
    solve(s, n - 1);
}

int main() {
    FASTIO;
    _init();

    while (true) {
        int n; cin >> n;
        if (cin.eof()) break;
        string s;
        solve(s, n);
        cout << s << endl;
    }

    return 0;
}
