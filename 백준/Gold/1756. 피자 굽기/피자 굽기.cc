#include <bits/stdc++.h>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int lld;
typedef vector<int> vi;
int binary_search(vi &arr, int start, int end, int target) {
	int mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (arr[mid] >= target) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}
	return start - 1;
}
int main() {
	FASTIO;
	int d, n; cin >> d >> n;
	vi da(d);
	int last = d;
	for (int i = 0; i < d; i++) {
		cin >> da[i];
		if (i != 0) da[i] = min<int>(da[i], da[i - 1]);
	}
	for (int i = 0; i < n; i++) {
		int r; cin >> r;
		last = binary_search(da, 0, last, r);
		//cout << last << ' ';
		if (last < 0) {
			cout << "0\n";
			return 0;
		}
	}
	cout << last + 1 << endl;

	return 0;
}

