#include <bits/stdc++.h>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifndef BOJ
    freopen("boj.in", "r", stdin);
#endif // BOJ
}

using namespace std;

using vi = vector<int>;

int _sum(const string& s) {
    int ret = 0;
    for (char ch : s) {
        if ('0' <= ch && ch <= '9') ret += ch - '0';
    }
    return ret;
}

bool compare(const string& a, const string& b) {
    if (a.size() == b.size()) {
        int sa = _sum(a), sb = _sum(b);
        if (sa == sb) {
            return a < b;
        }
        return sa < sb;
    }
    return a.size() < b.size();
}

int main() {
    FASTIO;
    _init();

    int n; cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end(), compare);

    for (string s : arr) cout << s << endl;

    return 0;
}
