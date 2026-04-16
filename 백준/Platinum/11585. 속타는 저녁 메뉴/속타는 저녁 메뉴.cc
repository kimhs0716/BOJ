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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    FASTIO;
    _init();

    int n; cin >> n;
    vi t(n), p(n);
    for (int i = 0; i < n; i++) {
        char ch; cin >> ch;
        t[i] = (int)ch;
    }
    for (int i = 0; i < n; i++) {
        char ch; cin >> ch;
        p[i] = (int)ch;
    }

    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (t[i] != p[i]) flag = false;
    }

    for (int i = 0; i < n; i++) {
        t.push_back(t[i]);
    }
    int m = kmp(t, p).size() - flag;

    int g = gcd(n, m);
    n /= g;
    m /= g;
    cout << m << '/' << n << endl;

    return 0;
}
