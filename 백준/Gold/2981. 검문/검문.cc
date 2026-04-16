#define _GLIBCXX_FILESYSTEM
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int lld;
vector<int> factors(int n) {
    int i = 1;
    vector<int> ret;
    while(i * i < n) {
        if(n % i == 0) {
            ret.push_back(i);
            ret.push_back(n / i);
        }
        i++;
    }
    if(i * i == n) ret.push_back(i);
    sort(ret.begin(), ret.end());
    return ret;
}
int main() {
    int n; cin >> n;
    vector<int> input(n);
    vector<int> arr;
    for(int i = 0; i < n; i++) cin >> input[i];
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            arr.push_back(abs(input[i] - input[j]));
        }
    }
    int res = arr[0];
    for(int i = 1; i < arr.size(); i++) res = gcd(res, arr[i]);
    vector<int> f = factors(res);
    for(int i = 1; i < f.size(); i++) cout << f[i] << ' ';
    return 0;
}