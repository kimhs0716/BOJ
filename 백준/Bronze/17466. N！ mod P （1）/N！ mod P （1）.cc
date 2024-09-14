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

ll fac(ll n, ll p) {
    ll ans = 1;
    for (ll i = 1; i <= n; i++) ans = ans * i % p;
    return ans;
}

ll _pow(ll n, ll r, ll m) {
    if (r == 0) return 1;
    ll ret = _pow(n, r >> 1, m);
    ret = ret * ret % m;
    if (r & 1) ret = ret * n % m;
    return ret;
}

ll inv(ll n, ll p) {
    return _pow(n, p - 2, p);
}

int main() {
    FASTIO;
    _init();

    ll n, p; cin >> n >> p;
    ll d = p - n;
    ll ans;
    if (d < n) {
        ll s = (d % 2) ? -1 : 1;
        ll fd = fac(d - 1, p);
        ll invf = inv(fd, p);
        ans = s * invf % p;
        if (ans < 0) ans += p;
    }
    else {
        ans = fac(n, p);
    }

    cout << ans << endl;

    return 0;
}
