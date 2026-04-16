#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, limit;
    cin >> n;

    vector<int> cache(n);
    for (int i = 0; i < n; i++) cin >> cache[i];

    cin >> limit;

    sort(cache.begin(), cache.end());
    int result = cache[0];

    if (cache[0] * n >= limit) {
        cout << (int)(limit / n) << "\n";
    } else {
        limit -= cache[0] * n;
        for (int i = 1; i < n; i++) {
            int curr = (cache[i] - cache[i - 1]) * (n - i);
            if (curr >= limit) {
                result += (int) (limit / (n - i));
                break;
            } else {
                limit -= curr;
                result = cache[i];
            }
        }
        cout << result << "\n";
    }
}