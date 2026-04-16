#include <iostream>
#define mod 10007
using namespace std;
typedef long long int lld;
lld pow(lld a, int n);
lld fac(lld n);
int main() {
    int n, k;
    cin >> n >> k;
    cout << ((fac(n) % mod) * (pow(fac(k) * fac(n - k) % mod, mod - 2) % mod)) % mod << endl;
	return 0;
}
lld pow(lld a, int n){
    if(n == 0) return 1;
    lld res = pow(a, n / 2) % mod;
    res *= res;
    res %= mod;
    if(n & 1) res *= a;
    res %= mod;
    return res;
}
lld fac(lld n){
    if(n == 0) return 1;
    return (n * fac(n - 1)) % mod;
}
