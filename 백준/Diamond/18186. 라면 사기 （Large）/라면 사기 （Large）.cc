#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
#ifndef BOJ
class debugstream {
public:
	ostream& os;
	debugstream(ostream& os) :os(os) {}
	template <typename T>
	ostream& operator<<(const T& obj) {
		return os << "#[DEBUG]: " << obj;
	}
};
debugstream dout(cout);
#endif
typedef long long int lld;
int main() {
	//FASTIO;
	lld n, b, c; scanf("%lld %lld %lld", &n, &b, &c);
	lld* arr = new lld[n];
	lld ans = 0;
	for (lld i = 0; i < n; i++) scanf("%lld", arr + i), ans += *(arr + i);
	ans *= b;
	if (b < c) {
		c = b;
	}
	for (lld i = 0; i < n - 2; i++) {
		if (arr[i + 1] > arr[i + 2]) {
			lld k = min<lld>(arr[i], arr[i + 1] - arr[i + 2]);
			arr[i] -= k, arr[i + 1] -= k;
			ans -= (b - c) * k;
		}
		lld k = min<lld>(min<lld>(arr[i], arr[i + 1]), arr[i + 2]);
		arr[i] -= k, arr[i + 1] -= k, arr[i + 2] -= k;
		ans -= 2 * (b - c) * k;
	}
	ans -= (b - c) * min<lld>(arr[n - 1], arr[n - 2]);
	printf("%lld\n", ans);
	//for (int i = 0; i < n; i++) cout << arr[i] << ' ';

	return 0;
}