#include <bits/stdc++.h>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int lld;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;
int get5(vi& arr) {
	int M = 0, sum = 0;
	for (int i = 0; i < 6; i++) M = max<int>(M, arr[i]), sum += arr[i];
	return sum - M;
}
int get3(vi& arr) {
	int s[] = {
		arr[0] + arr[1] + arr[2], arr[0] + arr[1] + arr[3], arr[0] + arr[2] + arr[4],
		arr[0] + arr[3] + arr[4], arr[1] + arr[2] + arr[5], arr[1] + arr[3] + arr[5],
		arr[2] + arr[4] + arr[5], arr[3] + arr[4] + arr[5]
	};
	int m = 2147483647;
	for (auto i : s) {
		m = min<int>(m, i);
	}
	return m;
}
int get2(vi& arr) {
	int s[] = {
		arr[0] + arr[1], arr[0] + arr[2], arr[0] + arr[3], arr[0] + arr[4],
		arr[1] + arr[2], arr[1] + arr[3], arr[1] + arr[5], arr[2] + arr[4],
		arr[2] + arr[5], arr[3] + arr[4], arr[3] + arr[5], arr[4] + arr[5]
	};
	int m = 2147483647;
	for (auto i : s) {
		m = min<int>(m, i);
	}
	return m;
}
int get1(vi& arr) {
	int m = 2147483647;
	for (auto i : arr) {
		m = min<int>(m, i);
	}
	return m;
}
int main() {
	lld n; cin >> n;
	vi arr(6); for (int i = 0; i < 6; i++) cin >> arr[i];
	if (n == 1) {
		cout << get5(arr) << endl;
	}
	else if (n == 2) {
		cout << get3(arr) * 4 + get2(arr) * 4 << endl;
	}
	else {
		cout << (5 * n * n - 16 * n + 12) * get1(arr) + \
			(8 * n - 12) * get2(arr) + 4 * get3(arr) << endl;
	}

	return 0;
}

