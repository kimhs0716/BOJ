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

int find(int* arr, int target, int size) {
    int lo = 0, hi = size - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] < target) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    if (arr[lo] == target) return lo;
    return -1;
}

int main() {
    FASTIO;
    _init();

    int n; cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int m; cin >> m;
    while (m--) {
        int t; cin >> t;
        if (find(arr, t, n) == -1) {
            cout << "0\n";
        }
        else {
            cout << "1\n";
        }
    }

    delete[] arr;

    return 0;
}
