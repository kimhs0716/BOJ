#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
using vl = vector<ll>;
using tlll = tuple<ll, ll, ll>;

void __init() {
#ifdef KIMHS
    freopen("boj.in", "r", stdin);
    freopen("boj.out", "w", stdout);
#endif
}

ll gcd(ll a, ll b) {
    a = abs(a), b = abs(b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

constexpr ll MOD = 1000000007;
constexpr ll INF = 1e10;

struct v2 {
    ll x, y;
    v2 operator+(const v2 &other) {
        return {x + other.x, y + other.y};
    }
    v2 operator-(const v2 &other) {
        return {x - other.x, y - other.y};
    }
    v2 operator/(const ll k) {
        return {x / k, y / k};
    }
};

ll area(v2 a, v2 b, v2 c) {
    return abs(a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y);
}

ostream& operator<<(ostream &os, v2 v) {
    return os << "(" << v.x << ", " << v.y << ")";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    __init();

    v2 a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    v2 a2b = b - a, b2c = c - b, c2a = a - c;
    ll gab = gcd(a2b.x, a2b.y);
    ll gbc = gcd(b2c.x, b2c.y);
    ll gca = gcd(c2a.x, c2a.y);

    if (gab == 1 || gbc == 1 || gca == 1) {
        cout << "-1\n";
        return 0;
    }

    a2b = a2b / gab, b2c = b2c / gbc, c2a = c2a / gca;

    ll min_s = INF, max_s = 0;

    max_s = max<ll>({
        area(a + a2b, b + b2c, c + c2a),
        area(a - c2a, b - a2b, c - b2c),
    });

    min_s = min<ll>({
        area(a + a2b, a - c2a, b + b2c),
        area(a + a2b, a - c2a, c - b2c),
        area(b - a2b, b + b2c, c + c2a),
        area(b - a2b, b + b2c, a - c2a),
        area(c + c2a, c - b2c, a + a2b),
        area(c + c2a, c - b2c, b - a2b),
    });


    cout << max_s << ' ' << min_s << '\n';

    return 0;
}