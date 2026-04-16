#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
typedef long long int lld;
int main() {
	lld n;
	cin >> n;
	if(n == 0){
        cout << 0;
        return 0;
	}
	if(n > 9223372030926249001){
        cout << 3037000500;
        return 0;
	}
	lld m = 0;
	lld M = sqrt((double)LONG_LONG_MAX);
	lld mid = (m + M) / 2;
	while (true) {
		//printf("%lld %lld %lld\n", m, mid, M);
		if (mid * mid < n && (mid + 1) * (mid + 1) >= n) break;
		if (mid * mid >= n) M = mid;
		else m = mid;
		mid = (m + M) / 2;
	}
	cout << mid + 1 << endl;
	return 0;
}
