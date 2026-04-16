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
constexpr ll MAX = 123456;

int main() {
    FASTIO;
    _init();

    while (true) {
        ll n; cin >> n;
        if (n == 0) break;
        ll m = 2 * n;
        char arr[2 * MAX + 1];
        for (ll i = 0; i <= m; i++) arr[i] = 1;
        arr[0] = arr[1] = 0;
        for (ll i = 2; i <= m; i++) {
            if (arr[i] == 0) continue;
            for (ll j = i + i; j <= m; j += i) {
                arr[j] = 0;
            }
        }
        ll cnt = 0;
        for (ll i = n + 1; i <= m; i++)
            if (arr[i]) cnt++;
        cout << cnt << endl;
    }

    return 0;
}
