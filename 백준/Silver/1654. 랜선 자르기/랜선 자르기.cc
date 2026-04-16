#include <iostream>
using namespace std;
int cut(int *arr, int len, int n);
int main(){
    int k, n;
    cin >> k >> n;
    int lan[k], M = (int)(1<<31) - 1;
    for(int i = 0; i < k; i++){
        cin >> lan[i];
        //M = min(M, lan[i]);
    }
    long long m = 1, mid;
    while(1){
        mid = (m + M) / 2;
        //cout << m << ", " << mid << ", " << M << endl;
        if(mid == m) break;
        int s = cut(lan, mid, k);
        if(s < n) M = mid;
        else m = mid;
    }
    if(cut(lan, mid + 1, k) == n) cout << mid + 1;
    else cout << mid;
    return 0;
}
int cut(int *arr, int len, int n){
    int res = 0;
    for(int i = 0; i < n; i++)
        res += arr[i] / len;
    return res;
}
