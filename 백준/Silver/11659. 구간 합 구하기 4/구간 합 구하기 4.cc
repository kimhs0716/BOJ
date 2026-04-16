#define _GLIBCXX_FILESYSTEM
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int lld;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    vector<int> sum(n + 1);
    sum[0] = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum[i + 1] = sum[i] + arr[i];
    }
    while(m--) {
        int i, j; cin >> i >> j;
        cout << sum[j] - sum[i - 1] << endl;
    }

    return 0;
}
