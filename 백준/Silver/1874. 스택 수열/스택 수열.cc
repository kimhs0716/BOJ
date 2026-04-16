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

    stack<int> st;
    int n; cin >> n;
    bool flag = true;
    int nxt = 1;
    vector<char> ans;

    for (int i = 0; i < n; i++) {
        int cur; cin >> cur;
        while (nxt <= cur) {
            st.push(nxt++);
            ans.push_back('+');
        }
        if (st.top() == cur) {
            st.pop();
            ans.push_back('-');
        }
        else {
            flag = false;
            break;
        }
    }

    if (flag) {
        for (char& i : ans) {
            cout << i << endl;
        }
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
