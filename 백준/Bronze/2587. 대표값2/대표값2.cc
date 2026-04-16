#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
#define endl '\n'
using namespace std;
typedef long long int lld;
int main(){
    vector<int> arr(5);
    for(int i = 0; i < 5; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    cout << accumulate(arr.begin(), arr.end(), 0) / 5 << endl;
    cout << arr[2] << endl;
    return 0;
}
