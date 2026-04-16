#include <iostream>
#include <vector>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;
using vi = vector<int>;

int main() {
	FASTIO;

	int n, m; cin >> n >> m;
	vi words(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (char ch : s) {
			words[i] |= 1 << (ch - 'a');
		}
	}
	
	int cur = (1 << 26) - 1;

	while (m--) {
		int o; char x;
		cin >> o >> x;
		cur ^= 1 << (x - 'a');
		int cnt = 0;
		for (auto i : words) {
			cnt += (i & cur) == i;
		}
		cout << cnt << endl;
	}

	return 0;
}