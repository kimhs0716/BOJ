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
using vl = vector<ll>;
using pll = pair<ll, ll>;

constexpr ll MOD = 1e9 + 7;
constexpr ll MAX = 1'000'001;

int main() {
    FASTIO;
    _init();

    map<char, int> priority {
        {'*', 0},
        {'/', 0},
        {'+', 1},
        {'-', 1},
        {'(', 2},
    };

    string expr; cin >> expr;
    stack<char> st;
    for (auto c : expr) {
        if ('A' <= c && c <= 'Z') {
            cout << c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            char e = st.top(); st.pop();
            while (e != '(' && !st.empty()) {
                cout << e;
                e = st.top(); st.pop();
            }
        }
        else {
            while (!st.empty() && priority[c] >= priority[st.top()]) {
                char e = st.top(); st.pop();
                cout << e;
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        char e = st.top(); st.pop();
        cout << e;
    }
    cout << endl;

    return 0;
}
