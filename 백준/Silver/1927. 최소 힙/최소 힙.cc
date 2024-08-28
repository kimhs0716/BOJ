#include <bits/stdc++.h>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void _init() {
#ifndef BOJ
      freopen("boj.in", "r", stdin);
#endif // BOJ
}

using namespace std;

using vi = vector<int>;

class min_heap {
private:
    int n, _size;
    vi arr;
    int inf = numeric_limits<int>::max();
public:
    min_heap(int n) {
        this->n = 1;
        while (this->n < n) this->n <<= 1;
        arr = vi(this->n + 5, inf);
        _size = 0;
    }

    void push(int x) {
        int cur = ++_size;
        arr[cur] = x;
        while (cur > 1) {
            if (arr[cur] < arr[cur / 2]) swap(arr[cur], arr[cur / 2]);
            cur >>= 1;
        }
    }

    int pop() {
        if (_size == 0) return 0;
        int ret = arr[1];
        int cur = 1;
        swap(arr[_size], arr[1]);
        arr[_size--] = inf;
        while (cur <= _size) {
            if (arr[cur] > arr[2 * cur] && arr[2 * cur] <= arr[2 * cur + 1]) {
                swap(arr[cur], arr[2 * cur]);
                cur = 2 * cur;
            }
            else if (arr[cur] > arr[2 * cur + 1] && arr[2 * cur + 1] <= arr[2 * cur]) {
                swap(arr[cur], arr[2 * cur + 1]);
                cur = 2 * cur + 1;
            }
            else cur = 2 * cur;
        }
        return ret;
    }

    void debug() {
        for (int i = 1; arr[i] != inf; i++) cout << arr[i] << ' ';
        cout << endl;
    }
};

int main() {
    FASTIO;
    _init();

    int n; cin >> n;
    min_heap pq(n);
    while (n--) {
        int x; cin >> x;
        if (x == 0) cout << pq.pop() << endl;
        else pq.push(x);
        //pq.debug();
    }

    return 0;
}
