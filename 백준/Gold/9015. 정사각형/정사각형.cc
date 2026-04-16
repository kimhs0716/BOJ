#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define hash_size 1024
using namespace std;
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
typedef long long int lld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<short, short> pss;
istream& operator>>(istream& is, pss& p) {
	return is >> p.first >> p.second;
}
inline int area(const pss& p1, const pss& p2) {
	return ((int)p1.first - p2.first) * ((int)p1.first - p2.first) + \
		((int)p1.second - p2.second) * ((int)p1.second - p2.second);
}
vector<pss> points;
set<pss> s;
int main() {
	FASTIO;
	int t; cin >> t;
	while (t--) {
		points.clear();
		s.clear();
		int M = 0;
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			pss p; cin >> p;
			points.push_back(p);
			s.insert(p);
		}
		for (int i = 0; i < n; i++) {
			pss pi = points[i];
			for (int j = i + 1; j < n; j++) {
				pss pj = points[j];
				int dx = pi.first - pj.first;
				int dy = pi.second - pj.second;
				int a = area(pi, pj);
				if (a < M) continue;

				pss p1, p2, p3, p4;
				p1 = { pi.first + dy, pi.second - dx };
				p2 = { pj.first + dy, pj.second - dx };
				p3 = { pi.first - dy, pi.second + dx };
				p4 = { pj.first - dy, pj.second + dx };

				if (-10000 <= p1.first && p1.first <= 10000 && \
					- 10000 <= p2.first && p2.first <= 10000 && \
					- 10000 <= p1.second && p1.second <= 10000 && \
					- 10000 <= p2.second && p2.second <= 10000) {
					if (s.find(p1) != s.end() && s.find(p2) != s.end()) M = a;
				}
				else if (-10000 <= p3.first && p3.first <= 10000 && \
					- 10000 <= p4.first && p4.first <= 10000 && \
					- 10000 <= p3.second && p3.second <= 10000 && \
					- 10000 <= p4.second && p4.second <= 10000) {
					if (s.find(p3) != s.end() && s.find(p4) != s.end()) M = a;
				}
			}
		}
		cout << M << endl;
	}

	return 0;
}