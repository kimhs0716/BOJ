#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) arr[i] = i + 1;
    while(m--) {
        int i, j; cin >> i >> j;
        swap(arr[i - 1], arr[j - 1]);
    }
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    delete[] arr;
    return 0;
}
