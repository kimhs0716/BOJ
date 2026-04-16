#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define pii pair<int, int>
using namespace std;
int main() {
    FASTIO;
    int r, c, n; cin >> n >> r;
    n--;
    while (n--) {
        cin >> c;
        int g = gcd(c, r);
        cout << r / g << '/' << c / g << endl;
    }
    return 0;
}
