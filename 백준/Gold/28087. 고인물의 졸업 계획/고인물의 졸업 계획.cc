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
#include <cassert>
#include <iomanip>

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
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr ll MOD = 1000;
constexpr ll INF = 1'000'000'001;

int main() {
    FASTIO;
    _init();

    int n, m; cin >> n >> m;
    int s = 0;
    vector<pii> ss, arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < m; i++) {
        while (s + arr[i].first > 2 * n) {
            s -= ss.back().first;
            ss.pop_back();
        }
        s += arr[i].first;
        ss.push_back(arr[i]);
        if (n <= s) break;
    }

    cout << ss.size() << endl;
    for (auto i: ss) {
        cout << i.second << endl;
    }

    return 0;
}
