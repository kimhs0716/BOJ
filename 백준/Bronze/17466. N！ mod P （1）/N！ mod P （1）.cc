#include <bits/stdc++.h>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifndef BOJ
    freopen("boj.in", "r", stdin);
#endif // BOJ
}

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

constexpr int INF = 2e8;

int main() {
    FASTIO;
    _init();

    ll n, p; cin >> n >> p;
    ll ans = 1;
    for (ll i = 1; i <= n; i++) ans = ans * i % p;
    cout << ans << endl;

    return 0;
}
