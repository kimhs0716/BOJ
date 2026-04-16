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
    int m = p.size(), j = 0;
    vi pi(m);
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
    int n = t.size(), m = p.size(), j = 0;
    vi pi = get_pi(p), ret;
    for (int i = 0; i < n; i++) {
        while (j > 0 && t[i] != p[j]) {
            j = pi[j - 1];
        }
        if (t[i] == p[j]) {
            if (j == m - 1) {
                ret.push_back(i - j);
            }
            else {
                j++;
            }
        }
    }
    return ret;
}

vi subseq(vi& arr, int left, int right) {
    vi ret;
    for (int i = left; i < right; i++) ret.push_back(arr[i]);
    return ret;
}

int main() {
    FASTIO;
    _init();

    int n, k; cin >> n >> k;
    vector<vi> arr(n);
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        arr[i] = vi(m);
        for (auto& j : arr[i]) cin >> j;
    }
    bool flag = false;
    for (int i = 0; i <= arr[0].size() - k; i++) {
        vi p = subseq(arr[0], i, i + k);
        int ok = 0;
        for (int j = 1; j < n; j++) {
            vi t = kmp(arr[j], p);
            reverse(p.begin(), p.end());
            vi s = kmp(arr[j], p);
            reverse(p.begin(), p.end());
            if (t.size() == 0 && s.size() == 0) break;
            ok++;
        }
        if (ok == n - 1) {
            flag = true;
            break;
        }
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
