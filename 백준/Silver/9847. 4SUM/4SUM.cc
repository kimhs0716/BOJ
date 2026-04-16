#include <iostream>
#include <vector>
#include <map>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

int main() {
	FASTIO;

	int a, b, c, d; cin >> a >> b >> c >> d;
	vi aa, bb, cc, dd;
	for (int i = 0; i < a; i++) {
		int n; cin >> n;
		aa.push_back(n);
	}
	for (int i = 0; i < b; i++) {
		int n; cin >> n;
		bb.push_back(n);
	}
	for (int i = 0; i < c; i++) {
		int n; cin >> n;
		cc.push_back(n);
	}
	for (int i = 0; i < d; i++) {
		int n; cin >> n;
		dd.push_back(n);
	}
	map<int, pii> m;
	for (int i : cc) {
		for (int j : dd) {
			m.insert({ i + j, {i, j} });
		}
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			auto it = m.find(-aa[i] - bb[j]);
			if (it != m.end()) {
				cout << aa[i] << ' ' << bb[j] << ' ' << it->second.first << ' ' << it->second.second << endl;
			}
		}
	}

	return 0;
}