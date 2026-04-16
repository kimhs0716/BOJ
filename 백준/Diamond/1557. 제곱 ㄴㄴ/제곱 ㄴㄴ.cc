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

typedef struct {
    ll num;
    set<ll> used;
} elem;

bool isprime[MAX];
vl primes;

ll count(ll n) {
    // n 이하의 제곱ㄴㄴ수의 개수를 return
    ll ret = n;
    queue<elem> q;
    for (ll p: primes) {
        if (p * p <= n) q.push({ p, set<ll> {p} });
    }
    bool flag = true;
    set<ll> visited;
    while (!q.empty()) {
        ll s = q.size();
        while (s--) {
            ll pp = q.front().num;
            set<ll> used = q.front().used;
            q.pop();
            if (flag) ret -= n / (pp * pp);
            else ret += n / (pp * pp);
            for (ll p: primes) {
                if (pp * pp * p * p > n) break;
                if (used.contains(p)) continue;
                if (visited.contains(pp * p)) continue;
                visited.insert(pp * p);
                used.insert(p);
                q.push({ pp * p, set<ll>(used)});
                used.erase(p);
            }
        }
        flag ^= true;
    }
    return ret;
}

int main() {
    FASTIO;
    _init();

    for (int i = 2; i < MAX; i++) {
        isprime[i] = true;
    }
    for (int i = 2; i < MAX; i++) {
        if (!isprime[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j < MAX; j += i) {
            isprime[j] = false;
        }
    }

    ll k; cin >> k;

    ll m = 0, M = k * 100;
    while (m + 1 < M) {
        ll mid = (m + M) / 2;
        ll cnt = count(mid);
        if (cnt < k) {
            m = mid;
        }
        else {
            M = mid;
        }
    }
    cout << m + 1 << endl;

    return 0;
}
