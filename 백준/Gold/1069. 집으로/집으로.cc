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
constexpr long double diff = 1e-12;
inline long double distance(long double x1, long double y1, long double x2, long double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main() {
	//FASTIO;
	long double x, y, d, t; cin >> x >> y >> d >> t;
	long double dis, time;
	dis = time = distance(0, 0, x, y);
	long double jump_v = d / t;
	if (jump_v > 1) {
		int jump_cnt = 0;
		long double cur_x = 0, cur_y = 0;
		while (cur_x < x) {
			cur_x += d * x / dis;
			cur_y += d * y / dis;
			jump_cnt++;
			//dout << distance(cur_x, cur_y, x, y) << endl;
			if (distance(cur_x, cur_y, x, y) <= d)
				time = min<long double>(time, t * (jump_cnt + 1));
			time = min<long double>(time, t * jump_cnt + distance(cur_x, cur_y, x, y));
		}
	}
	time = min<long double>(time, t * (int)(dis / d) + 2 * t);

	cout.precision(10);
	cout << fixed << time << endl;

	return 0;
}