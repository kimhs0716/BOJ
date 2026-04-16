//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <utility> // pair
#include <set>
#include <queue>

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
using vl = vector<ll>;
using pll = pair<ll, ll>;

constexpr ll MOD = 1e9 + 7;
constexpr ll MAX = 1'000'001;

vl get_pi(vl &p) {
    ll m = p.size(), j = 0;
    vl pi(m);
    for (ll i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            pi[i] = ++j;
            if (j == m - 1) {
                j = pi[j];
            }
        }
    }
    return pi;
}

vl kmp(vl &s, vl &p) {
    vl pi = get_pi(p), ret;
    ll n = s.size(), m = p.size(), j = 0;
    for (ll i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }
        if (s[i] == p[j]) {
            if (j == m - 1) {
                ret.push_back(i - j);
                j = pi[j];
            }
            else j++;
        }
    }
    return ret;
}

vl factors(ll n) {
    vl ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.rbegin(), ret.rend());
    return ret;
}

int main() {
    FASTIO;
    _init();

    string ss; cin >> ss;
    vl s(ss.begin(), ss.end());
    vl pi = get_pi(s);
    // cout << ss.length() << endl;
    // for (auto i: pi) cout << i << ' ';
    // cout << endl;

    ll l = pi.back();
    while (l) {
        vl p(s.begin(), s.begin() + l);
        vl matched = kmp(s, p);
        if (matched.size() >= 3) {
            for (ll ch: p) cout << (char)ch;
            cout << endl;
            return 0;
        }
        l = pi[l - 1];
    }

    cout << "-1\n";

    return 0;
}
