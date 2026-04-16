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
	Point() {}
	Point(int x, int y) :x(x), y(y) {
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
	int n, width, k; cin >> n >> width >> k;
	vector<Point> arr;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		for (int j = 0; j < k; j++) {
			if (j & 1) arr.push_back(Point((j + 1) * width - x, y));
			else arr.push_back(Point(x + width * j, y));
		}
	}
	sort(arr.begin(), arr.end());

	//for (auto i : arr) dout << i.x << ' ' << i.y << endl; //<< ' ' << i.tan.first << ' ' << i.tan.second << endl;

	int M = 0;
	for (auto iter = arr.begin(); iter < arr.end(); iter++) {
		pii temp_tan = iter->tan;
		int cnt = 0;
		while (iter->tan == temp_tan) {
			iter++; cnt++;
			if (iter == arr.end()) break;
		}
		iter--;
		M = max<int>(M, cnt);
		//dout << temp_tan.first << ' ' << temp_tan.second << ' ' << cnt << endl;
	}
	cout << M << endl;

	return 0;
}