#include <iostream>
#include <map>
using namespace std;
int main(){
    map<int, int> m;
    int n;
    cin >> n;
    int arr[n];
    int dp[n];
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        m[a] = b;
    }
    int cnt = 0;
    for(int i = 1; i <= 500; i++){
        if(m[i]) {
            arr[cnt++] = m[i];
        }
    }
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        int m = 0;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i] && m < dp[j]){
                m = dp[j];
            }
        }
        dp[i] = m + 1;
    }
    int M = 0;
    for(int i = 0; i < n; i++)
        M = max(M, dp[i]);
    cout << n - M << endl;
    return 0;
}
