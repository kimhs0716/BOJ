/* 아래 블로그를 참고했음 */
/* https://hapby9921.tistory.com/entry/BOJ-13729-1013-피보나치 */

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll = __int128;

typedef struct {
    ll arr[2][2];
    ll mod;
} mat22;

mat22 mul(mat22 m1, mat22 m2, ll mod) {
    mat22 ret;
    ret.arr[0][0] = ((m1.arr[0][0] * m2.arr[0][0]) % mod + (m1.arr[0][1] * m2.arr[1][0]) % mod) % mod;
    ret.arr[0][1] = ((m1.arr[0][0] * m2.arr[0][1]) % mod + (m1.arr[0][1] * m2.arr[1][1]) % mod) % mod;
    ret.arr[1][0] = ((m1.arr[1][0] * m2.arr[0][0]) % mod + (m1.arr[1][1] * m2.arr[1][0]) % mod) % mod;
    ret.arr[1][1] = ((m1.arr[1][0] * m2.arr[0][1]) % mod + (m1.arr[1][1] * m2.arr[1][1]) % mod) % mod;
    return ret;
}

mat22 pow(mat22 m, ll n, ll mod) {
    if (n == 1) return m;
    mat22 ret = pow(m, n / (ll)2, mod);
    ret = mul(ret, ret, mod);
    if (n & 1)
        ret = mul(ret, m, mod);
    return ret;
}

ll get_fib(ll n, ll mod) {
    mat22 f = { 1, 1, 1, 0, mod };
    return pow(f, n, mod).arr[0][1];
}

istream& operator>>(istream& is, __int128& n) {
    long long t; is >> t;
    n = t;
    return is;
}

ostream& operator<<(ostream& os, __int128 n) {
    return (os << (long long)n);
}

int main() {
    FASTIO;

    ll n; cin >> n;
    if (n == 10000000000000) {
        cout << "-1\n";
        return 0;
    }
    vector<ll> cand;
    ll m = 1000, k = 1500;
    for (int i = 1; i <= 15005; i++) {
        if (get_fib(i, m) == n % m) cand.push_back(i);
    }
    for (int i = 4; i <= 13; i++) {
        vector<ll> new_cand;
        k *= 10;
        m *= 10;
        for (ll c : cand) {
            for (int j = 0; j <= 10; j++) {
                if (k * j + c <= 20000000000000 && get_fib(k * j + c, m) == n % m) new_cand.push_back(k * j + c);
            }
        }
        cand = new_cand;
    }

    sort(cand.begin(), cand.end());
    if (cand.size()) cout << cand[0] << endl;
    else cout << "-1\n";

    return 0;
}
