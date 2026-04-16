#include <iostream>
#include <vector>

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF (ll)(1e18)

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    FASTIO;

    ll n, sum = 0; cin >> n;
    vector<vll> arr(n, vll(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[j][i];
            sum += arr[j][i];
        }
    }

    ll ans = -INF;
    for (int i = 0; i < (1 << n); i++) {
        ll tmp = 0;
        for (int r = 0; r < n; r++) {
            ll s1 = 0, s2 = 0;
            for (int c = 0; c < n; c++) {
                if ((i >> c) & 1) s1 += arr[r][c];
                else s2 += arr[r][c];
            }
            tmp += max<ll>(s1, s2);
        }
        // cout << "i: " << i << ", tmp: " << tmp << endl;
        ans = max<ll>(ans, sum - tmp);
    }

    cout << ans << endl;

    return 0;
}
