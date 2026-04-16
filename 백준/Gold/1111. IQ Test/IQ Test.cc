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
using ll = long long int;

int main() {
    FASTIO;
    _init();

    int n; cin >> n;
    vi arr(n); 
    for (auto& i : arr) cin >> i;
    if (n == 1) cout << "A\n";
    else if (n == 2) {
        if (arr[0] == arr[1]) cout << arr[0] << endl;
        else cout << "A\n";
    }
    else {
        int a, b;
        for (a = -250; a <= 250; a++) {
            int b = arr[1] - a * arr[0];
            if (arr[0] * a + b == arr[1] && arr[1] * a + b == arr[2]) {
                bool flag = true;
                for (int i = 0; i < n - 1; i++) {
                    if (arr[i] * a + b != arr[i + 1]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    cout << arr.back() * a + b << endl;
                    return 0;
                }
            }
        }
        cout << "B\n";
    }

    return 0;
}
