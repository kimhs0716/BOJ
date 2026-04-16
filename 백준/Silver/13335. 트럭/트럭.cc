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
using pll = pair<ll, ll>;

int main() {
    FASTIO;
    _init();

    int n, w, l; cin >> n >> w >> l;
    vi arr(n);
    for (auto& i : arr) cin >> i;
    queue<int> q;
    int time = 0, sum = 0, idx = 0;

    while (true) {
        if (idx == n) break;
        if (w <= q.size()) {
            sum -= q.front();
            q.pop();
        }
        if (sum + arr[idx] <= l) {
            sum += arr[idx];
            q.push(arr[idx++]);
        }
        else q.push(0);
        time++;

        //cout << time << ": ";
        //for (int i = 0; i < q.size(); i++) {
        //    cout << q.front() << ' ';
        //    q.push(q.front());
        //    q.pop();
        //}
        //cout << endl;
    }

    cout << time + w << endl;

    return 0;
}
