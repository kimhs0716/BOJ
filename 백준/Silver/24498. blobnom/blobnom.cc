#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main(){
    FASTIO;
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    if(n == 1){
        cout << arr[0] << endl;
        return 0;
    }
    if(n == 2){
        cout << max(arr[0], arr[1]) << endl;
        return 0;
    }
    int M = 0;
    for(int i = 0; i < n; i++)
        M = max(M, arr[i]);
    for(int i = 1; i < n - 1; i++){
        if(arr[i] < 1 || arr[i - 1] < 1 || arr[i + 1] < 1) continue;
        M = max(M, arr[i] + min(arr[i - 1], arr[i + 1]));
    }
    cout << M << endl;
}
