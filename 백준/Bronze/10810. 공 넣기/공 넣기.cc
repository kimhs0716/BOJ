#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    int *arr = new int[n];
    memset(arr, 0, n * 4);
    while(m--) {
        int i, j, k; cin >> i >> j >>k ;
        i--;
        while(i < j) arr[i++] = k;
    }
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    delete[] arr;
    return 0;
}
