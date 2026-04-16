#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;
typedef long long int lld;
int main(){
    int t; cin >> t;
    vector<int> v;
    while(t--) {
        int n; cin >> n;
        v.push_back(n);
    }
    int M = *max_element(v.begin(), v.end());
    lld arr[M + 1][11];
    for(int i = 0; i < 10; i++) arr[1][i] = 1;
    arr[1][10] = 10;
    for(int i = 2; i <= M; i++){
        arr[i][0] = 1;
        lld s = 1;
        for(int j = 1; j < 10; j++) s += arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        arr[i][10] = s;
    }
    for(auto iter = v.begin(); iter < v.end(); iter++){
        cout << arr[*iter][10] << endl;
    }
    return 0;
}
