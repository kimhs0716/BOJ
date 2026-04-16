//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <utility> // pair

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
constexpr ll MAX = 10001;

int main() {
    FASTIO;
    _init();

    char arr[MAX];
    for (char& i : arr) i = 1;
    arr[0] = arr[1] = 0;
    for (ll i = 2; i < MAX; i++) {
        if (arr[i] == 0) continue;
        for (ll j = i + i; j < MAX; j += i) {
            arr[j] = 0;
        }
    }

    ll tc; cin >> tc;
    while (tc--) {
        ll n; cin >> n;
        ll a = n / 2, b = n - a;
        while (!(arr[a] && arr[b])) a--, b++;
        cout << a << ' ' << b << endl;
    }

    return 0;
}
