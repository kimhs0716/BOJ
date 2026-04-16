#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <climits>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;
typedef long long int lld;
int main(){
    FASTIO;
    int n; cin >> n;
    vector<int> arr(3);
    lld m = LONG_LONG_MAX;
    vector<lld> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = 0; i < n - 2; i++){
        int l = i + 1, r = n - 1;
        while(l < r){
            lld a = v[i] + v[l] + v[r];
            if(abs(a) < m){
                m = abs(a);
                arr[0] = v[i], arr[1] = v[l], arr[2] = v[r];
            }
            if(a == 0) break;
            if(a > 0) r--;
            else l++;
        }
    }
    cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
    return 0;
}
