#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int *arr = new int[n + 1];
    for(int i = 1; i <= n; i++) arr[i] = i;

    while(m--) {
        int i, j; cin >> i >> j;
        for(int k = i; k <= (i + j) / 2; k++) {
            swap(arr[k], arr[i + j - k]);
        }
    }

    for(int i = 1; i <= n; i++) cout << arr[i] << ' ';

    delete[] arr;

    return 0;
}
