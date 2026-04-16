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
constexpr ll MAX = 4000001;

char arr[MAX];

int main() {
    FASTIO;
    _init();

    ll n; cin >> n;

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    for (char& i : arr) i = 1;
    vl primes;
    arr[0] = arr[1] = 0;
    for (ll i = 2; i <= n; i++) {
        if (arr[i] == 0) continue;
        primes.push_back(i);
        for (ll j = i + i; j <= n; j += i) {
            arr[j] = 0;
        }
    }

    ll left = 0, right = 0;
    ll s = 0;
    ll ans = 0;
    while (left <= primes.size()) {
        // cout << left << ' ' << right << ' ' << s << endl;
        if (right == primes.size() || s >= n) {
            s -= primes[left++];
        }
        else {
            s += primes[right++];
        }
        if (s == n) ans++;
    }

    cout << ans << endl;

    return 0;
}
