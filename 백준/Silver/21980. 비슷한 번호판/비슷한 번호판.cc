#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;
using vi = vector<int>;

typedef struct lp {
	int arr[26];
	int upper;
	string str;
} lp;

struct MyHash {
	size_t operator()(const lp& l) const {
		hash<int> hash_func;
		int ret = 0;
		for (int i = 0; i < 26; i++) {
			ret ^= hash_func(l.arr[i]) ^ hash_func(i);
		}

		return ret ^ hash_func(l.upper);
	}
};

bool operator==(lp lp1, lp lp2) {
	if (lp1.upper == lp2.upper) {
		bool flag = true;
		for (int i = 0; i < 26; i++) flag &= lp1.arr[i] == lp2.arr[i];
		return flag;
	}
	return false;
}

ostream& operator<<(ostream& os, const lp& l) {
	return os << l.str;
}

int main() {
	FASTIO;

	int tc; cin >> tc;
	for (int i = 1; i <= tc; i++) {
		unordered_map<lp, int, MyHash> m;
		int n, k; cin >> n >> k;
		vector<lp> arr(n);
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			arr[i].str = s;
			for (auto ch : s) {
				arr[i].arr[toupper(ch) - 'A']++;
				arr[i].upper += isupper(ch);
			}
			if (m.find(arr[i]) == m.end()) {
				m.insert({ arr[i], 0 });
			}
			m[arr[i]]++;
		}

		int ans = 0;
		for (auto& it : m) {
			// cout << it.first << ' ' << it.second << endl;
			ans += it.second * (it.second - 1) / 2;
		}
		cout << ans << endl;
	}

	return 0;
}