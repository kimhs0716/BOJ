#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define pii pair<int, int>
using namespace std;
int euler_phi(int n);
bool isprime(int n);
int main() {
    FASTIO;
    int t, n; cin >> t;
    vector<int> v;
    v.push_back(0), v.push_back(3);
    for (int i = 2; i <= 1000; i++) {
        v.push_back(v[i - 1] + 2 * euler_phi(i));
    }
    while (t--) {
        cin >> n;
        cout << v[n] << endl;
    }
    return 0;
}
int euler_phi(int n) {
    map<int, int> factors;
    int ret = 1;
    //factors[2] = 0;
    while (n % 2 == 0) {
        factors[2]++;
        n >>= 1;
    }
    int i = 3;
    while (i <= n) {
        if (n % i == 0) {
            if (factors.find(i) == factors.end()) factors[i] = 0;
            factors[i]++;
            n /= i;
            continue;
        }
        i += 2;
    }
    for (auto iter = factors.begin(); iter != factors.end(); iter++) {
        //cout << iter->first << ": " << iter->second << endl;
        ret *= pow(iter->first, iter->second) - pow(iter->first, iter->second - 1);
    }
    return ret;
}