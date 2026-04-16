#include <bits/stdc++.h>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define inf 1987654321
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
typedef struct Point {
	int x, y;
	pii tan;
	bool is_start;
	Point() {}
	Point(int x, int y, bool is_start) :x(x), y(y), is_start(is_start) {
		int g = gcd(x, y);
		tan = { x / g, y / g };
	}
	bool operator<(Point& p) {
		return (long double)tan.second / tan.first < (long double)p.tan.second / p.tan.first;
	}
	bool operator>(Point& p) {
		return (long double)tan.second / tan.first > (long double)p.tan.second / p.tan.first;
	}
} Point;
int main() {
	FASTIO;
	int n; cin >> n;
	vector<Point> arr;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		Point p1 = Point(x1, y1, 1);
		Point p2 = Point(x2, y2, 0);
		if (p2 < p1) {
			p2.is_start = 1;
			p1.is_start = 0;
		}
		arr.push_back(p1);
		arr.push_back(p2);
	}
	sort(arr.begin(), arr.end());

	int cnt = 0, M = 0;

	for (auto iter = arr.begin(); iter < arr.end(); iter++) {
		vector<Point> temp;
		pii temp_tan = iter->tan;
		while (iter->tan == temp_tan) {
			temp.push_back(*iter);
			iter++;
			if (iter == arr.end()) break;
		}
		iter--;
		for (vector<Point>::iterator i = temp.begin(); i < temp.end(); i++) {
			if (i->is_start) cnt++;
		}
		M = max<int>(M, cnt);
		for (vector<Point>::iterator i = temp.begin(); i < temp.end(); i++) {
			if (!i->is_start) cnt--;
		}
	}
	cout << M << endl;

	return 0;
}