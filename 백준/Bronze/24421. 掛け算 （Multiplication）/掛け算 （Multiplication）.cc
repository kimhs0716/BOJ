#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;
typedef long long int lld;
int main(){
    FASTIO;
    int n, cnt = 0; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int x = 0; x < n - 2; x++){
        for(int y = x + 1; y < n - 1; y++){
            for(int z = y + 1; z < n; z++){
                if(arr[x] * arr[y] == arr[z]) cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
