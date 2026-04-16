#include <iostream>
#define mod 1000000007
using namespace std;
long long _pow(long long n, long long r) {
	if (r == 0) return 1;
	long long res = _pow(n, r >> 1);
	res = res * res % mod;
	if (r & 1) res = res * n % mod;
	return res;
}
long long _inv(long long n) {
	return _pow(n, mod - 2);
}
int main() {
	long long a, b; cin >> a >> b;
	if (a == 1) cout << b % mod << endl;
	else {
		cout << (_pow(a, b) - 1) * _inv(a - 1) % mod << endl;
	}
	return 0;
}