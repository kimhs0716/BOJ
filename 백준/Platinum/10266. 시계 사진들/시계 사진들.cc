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

vi get_pi(vi& p) {
    int m = p.size();
    vi pi(m);
    int j = 0;
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

vi kmp(vi& t, vi& p) {
    vi ans;
    vi pi = get_pi(p);
    int n = t.size(), m = p.size(), j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && t[i] != p[j]) {
            j = pi[j - 1];
        }
        if (t[i] == p[j]) {
            if (j == m - 1) {
                ans.push_back(i - j);
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }
    return ans;
}

int main() {
    FASTIO;
    _init();

    int n; cin >> n;
    vi arr1(n), arr2(n), diff1, diff2;
    for (auto& i : arr1) cin >> i;
    for (auto& i : arr2) cin >> i;
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    arr1.push_back(arr1[0] + 360000);
    arr2.push_back(arr2[0] + 360000);
    for (int i = 0; i < n; i++) {
        diff1.push_back(arr1[i + 1] - arr1[i]);
        diff2.push_back(arr2[i + 1] - arr2[i]);
    }
    for (int i = 0; i < n; i++) {
        diff1.push_back(diff1[i]);
    }

    //for (auto i : diff1) {
    //    cout << i << ' ';
    //}
    //cout << endl;
    //for (auto i : diff2) {
    //    cout << i << ' ';
    //}
    //cout << endl;

    vi ans = kmp(diff1, diff2);
    if (ans.empty()) cout << "im";
    cout << "possible\n";

    return 0;
}
