#include <iostream>
#include <deque>
#include <queue>
#include <cassert>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
    FASTIO;
    
	int N, L; cin >> N >> L;
    assert(2 * L <= N + 1);
	priority_queue<pii, vector<pii>, less<pii>> pq;
	deque<int> dq;

	for (int i = 0; i < 2 * L - 2; i++) {
		int inp; cin >> inp;
		dq.push_back(inp);
		pq.push(make_pair(dq.back(), i));
	}
	for (int i = 2 * L - 2; i < N; i++) {
		int inp; cin >> inp;
		dq.push_back(inp);
		pq.push(make_pair(dq.back(), i));
		while (pq.top().second <= i - 2 * L + 1) pq.pop();
		cout << pq.top().first << ' ';
	}
	cout << endl;

	return 0;
}