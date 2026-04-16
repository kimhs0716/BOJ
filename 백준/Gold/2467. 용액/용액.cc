//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <utility> // pair
#include <set>
#include <queue>
#include <stack>
#include <map>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifndef BOJ
    freopen("boj.in", "r", stdin);
    freopen("boj.out", "w", stdout);
#endif // BOJ
}

using namespace std;

using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;

constexpr ll MOD = 1e9 + 7;
constexpr ll MAX = 1'000'001;

int main() {
    FASTIO;
    _init();

    int n; cin >> n;
    vi arr(n);
    int x = 0, y = 0, m = 2147483647;
    for (auto& i: arr) cin >> i;

    int left = 0, right = n - 1;
    while (left < right) {
        int s = arr[left] + arr[right];
        if (abs(s) < m) {
            m = abs(s);
            x = left;
            y = right;
        }
        if (s < 0) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << arr[x] << ' ' << arr[y] << endl;

    return 0;
}
