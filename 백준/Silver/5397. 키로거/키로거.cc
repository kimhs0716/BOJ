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
using ll = long long int;

int main() {
    FASTIO;
    _init();

    int tc; cin >> tc;
    while (tc--) {
        stack<char> left, right;
        string s; cin >> s;
        for (auto& ch : s) {
            if (ch == '<') {
                if (left.size()) {
                    right.push(left.top());
                    left.pop();
                }
            }
            else if (ch == '>') {
                if (right.size()) {
                    left.push(right.top());
                    right.pop();
                }
            }
            else if (ch == '-') {
                if (left.size()) left.pop();
            }
            else {
                left.push(ch);
            }
        }
        string ans;
        while (!left.empty()) {
            ans.push_back(left.top());
            left.pop();
        }
        reverse(ans.begin(), ans.end());
        while (!right.empty()) {
            ans.push_back(right.top());
            right.pop();
        }
        cout << ans << endl;
    }

    return 0;
}
