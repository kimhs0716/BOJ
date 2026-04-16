#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 987654321
#define MOD 1000000007

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    FASTIO;

    string s, t; cin >> s >> t;
    queue<string> q;
    q.push(t);
    while (!q.empty()) {
        string c = q.front(); q.pop();
        if (c == s) {
			cout << 1 << endl;
			return 0;
		}
        if (c.size() <= s.size()) continue;
        if (c.back() == 'A') {
            string tmp = c.substr(0, c.size() - 1);
            q.push(tmp);
        }
        if (c.front() == 'B') {
            reverse(c.begin(), c.end());
            string tmp = c.substr(0, c.size() - 1);
            q.push(tmp);
        }
    }
    cout << 0 << endl;

    return 0;
}
