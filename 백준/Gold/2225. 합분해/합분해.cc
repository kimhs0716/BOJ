#include <iostream>
#include <cstring>
#define mod 1000000000
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin >> n >> k;
    int arr[201][201];
    memset(arr, 0, sizeof(int) * 40401);
    for(int i = 1; i <= k; i++)
        arr[i][1] = i;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= k; j++){
            arr[j][i] = arr[j][i - 1] + arr[j - 1][i];
            arr[j][i] %= mod;
        }
    }
    cout << arr[k][n] << endl;
    return 0;
}
