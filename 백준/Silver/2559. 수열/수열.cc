#include <iostream>
#include <climits>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int sum = 0, mi = INT_MIN;
    for(int k = 0; k < m; k++) sum += arr[k];
    for(int i = 0; i <= n - m; i++){
        mi = max(mi, sum);
        sum -= arr[i];
        sum += arr[i + m];
    }
    cout << mi;
    return 0;
}
