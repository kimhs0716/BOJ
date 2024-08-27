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
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;

using sticker = struct sticker {
    int r, c;
    vvc arr;
    sticker(int r, int c) :r(r), c(c) {
        arr = vvc(r, vc(c));
    }
};

istream& operator>>(istream& is, sticker& st) {
    int n;
    for (int i = 0; i < st.r; i++) {
        for (int j = 0; j < st.c; j++) {
            is >> n;
            st.arr[i][j] = n;
        }
    }
    return is;
}

void rotate(sticker& st) {
    int r = st.r, c = st.c;
    vvc temp(c, vc(r));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            temp[j][r - i - 1] = st.arr[i][j];
        }
    }
    st.r = c;
    st.c = r;
    st.arr = temp;
}

bool check(vvc& arr, sticker& st, int r, int c) {
    int n = arr.size(), m = arr[0].size();
    for (int i = 0; i < st.r; i++) {
        for (int j = 0; j < st.c; j++) {
            int nr = i + r;
            int nc = j + c;
            if (nr < 0 || nr >= n) return 0;
            if (nc < 0 || nc >= m) return 0;
            if (st.arr[i][j] && arr[nr][nc]) return 0;
        }
    }
    return 1;
}

int stick(vvc& arr, sticker& st, int r, int c) {
    int n = arr.size(), m = arr[0].size();
    int ret = 0;
    for (int i = 0; i < st.r; i++) {
        for (int j = 0; j < st.c; j++) {
            arr[r + i][c + j] |= st.arr[i][j];
            ret += st.arr[i][j];
        }
    }
    return ret;
}

pii find(vvc& arr, sticker& st) {
    int n = arr.size(), m = arr[0].size();
    for (int dir = 0; dir < 4; dir++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (check(arr, st, i, j)) return { i, j };
            }
        }
        rotate(st);
    }
    return { -1, -1 };
}

int main() {
    FASTIO;
    _init();

    int n, m, k; cin >> n >> m >> k;
    vvc arr(n, vc(m));
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int r, c; cin >> r >> c;
        sticker st(r, c);
        cin >> st;
        pii coord = find(arr, st);
        int _r = coord.first, _c = coord.second;
        if (_r != -1) ans += stick(arr, st, _r, _c);

        // DEBUG
        //cout << "=============================\n";
        //cout << "#[DEBUG] k: " << i << endl;
        //cout << "#[DEBUG] ans: " << ans << endl;
        //for (int r = 0; r < n; r++) {
        //    for (int c = 0; c < m; c++) {
        //        cout << (int)arr[r][c] << ' ';
        //    }
        //    cout << endl;
        //}
    }

    cout << ans << endl;

    return 0;
}
