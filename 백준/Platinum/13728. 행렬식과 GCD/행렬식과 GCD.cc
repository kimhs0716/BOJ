#include <iostream>
#include <numeric>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;

using ll = long long;

constexpr int mod = 1e9 + 7;

typedef struct {
    ll arr[2][2];
} mat22;
mat22 pow(mat22 m, ll n);
mat22 mul(mat22 m1, mat22 m2);

int gcd(int, int);
ll get_fib(int n);

int main() {
    FASTIO;

    int n; cin >> n;
    ll s = 0;

    for (int i = 1; i <= n; i++) s = (s + get_fib(gcd(i + 1, n + 1))) % mod;

    cout << s << endl;

    return 0;
}

mat22 pow(mat22 m, ll n) {
    if (n == 1) return m;
    mat22 ret = pow(m, n / 2);
    ret = mul(ret, ret);
    if (n & 1)
        ret = mul(ret, m);
    return ret;
}
mat22 mul(mat22 m1, mat22 m2) {
    mat22 ret;
    ret.arr[0][0] = ((m1.arr[0][0] * m2.arr[0][0]) % mod + (m1.arr[0][1] * m2.arr[1][0]) % mod) % mod;
    ret.arr[0][1] = ((m1.arr[0][0] * m2.arr[0][1]) % mod + (m1.arr[0][1] * m2.arr[1][1]) % mod) % mod;
    ret.arr[1][0] = ((m1.arr[1][0] * m2.arr[0][0]) % mod + (m1.arr[1][1] * m2.arr[1][0]) % mod) % mod;
    ret.arr[1][1] = ((m1.arr[1][0] * m2.arr[0][1]) % mod + (m1.arr[1][1] * m2.arr[1][1]) % mod) % mod;
    return ret;
}

int gcd(int a, int b) {
    int r = 1;
    while (r != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ll get_fib(int n) {
    mat22 f = { 1, 1, 1, 0 };
    mat22 res = pow(f, n);
    return res.arr[0][1];
}