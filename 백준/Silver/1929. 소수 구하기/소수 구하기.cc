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
constexpr ll MAX = 1e6;

int main() {
    FASTIO;
    _init();

    ll n, m; cin >> n >> m;
    vl primes;
    char arr[MAX + 1];
    for (int i = 0; i <= m; i++) arr[i] = 1;
    for (int i = 2; i <= m; i++) {
        if (arr[i] == 0) continue;
        primes.push_back(i);
        for (int j = i + i; j <= m; j += i) {
            arr[j] = 0;
        }
    }

    for (auto i: primes) {
        if (i < n) continue;
        cout << i << endl;
    }


    return 0;
}
