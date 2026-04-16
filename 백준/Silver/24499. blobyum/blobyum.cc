#include <iostream>
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int s = 0, M = 0;
    for(int i = 0; i < k; i++) s += arr[i];
    M = s;
    for(int i = 0; i < n; i++){
        s += arr[(i + k) % n];
        s -= arr[i];
        M = max(M, s);
    }
    cout << M << endl;
}
