#include <bits/stdc++.h>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifndef BOJ
	freopen("boj.in", "r", stdin);
	// freopen("boj.out", "w", stdout);
#endif // BOJ
}

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long int;

vi get_pi(vi& p) {
	int m = p.size(), j = 0;
	vi pi(m);
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

vi kmp(vi& s, vi& p) {
	vi pi = get_pi(p);
	int n = s.size(), m = p.size(), j = 0;
	vi ret;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ret.push_back(i - j);
				j = pi[j];
			}
			else j++;
		}
	}
	return ret;
}

int main() {
	FASTIO;
	_init();

	int tc; cin >> tc;
	while (tc--) {
		string order, org_s, cip_s; cin >> order >> org_s >> cip_s;
		map<char, int> ci;
		vi ans;
		for (int i = 0; i < order.size(); i++) {
			ci[order[i]] = i;
		}
		if (org_s.size() == 1) {
			map<char, int> cnt;
			for (int i = 0; i < cip_s.size(); i++) {
				cnt[cip_s[i]]++;
			}
			for (auto it : cnt) {
				if (it.second == 1) {
					ans.push_back(ci[it.first] - ci[org_s[0]]);
					if (ans.back() < 0) ans.back() += order.size();
				}
			}
		}
		else {
			vi org, cip;
			for (int i = 0; i < org_s.size() - 1; i++) {
				org.push_back(ci[org_s[i + 1]] - ci[org_s[i]]);
				if (org.back() < 0) org.back() += order.size();
			}
			for (int i = 0; i < cip_s.size() - 1; i++) {
				cip.push_back(ci[cip_s[i + 1]] - ci[cip_s[i]]);
				if (cip.back() < 0) cip.back() += order.size();
			}
			vi indices = kmp(cip, org);
			map<int, int> m;
			for (int idx : indices) {
				int a = ci[cip_s[idx]] - ci[org_s[0]];
				if (a < 0) a += order.size();
				m[a]++;
			}

			for (auto it : m) {
				if (it.second == 1) ans.push_back(it.first);
			}
		}
		sort(ans.begin(), ans.end());

		if (ans.size() == 0) cout << "no solution" << endl;
		else if (ans.size() == 1) {
			cout << "unique: " << ans[0] << endl;
		}
		else {
			cout << "ambiguous: ";
			for (auto i : ans) cout << i << ' ';
			cout << endl;
		}
	}

	return 0;
}
