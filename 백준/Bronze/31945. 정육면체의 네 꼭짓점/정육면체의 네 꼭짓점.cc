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

    int arr[8][3];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][2-j] = (i >> j) & 1;
        }
    }

    int tc; cin >> tc;
    while (tc--) {
        int p[4];
        for (int &i : p) {
            cin >> i;
        }
        bool flag = false;
        for (int i = 0; i < 3; i++) {
            bool flag2 = true;
            for (int j : p) {
                if (arr[j][i] != arr[p[0]][i]) flag2 = false;
            }
            if (flag2) {
                flag = true;
                cout << "YES\n";
                break;
            }
        }
        if (!flag) {
            cout << "NO\n";
        }
    }

    return 0;
}
