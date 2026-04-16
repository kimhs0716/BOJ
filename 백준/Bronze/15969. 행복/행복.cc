#include <iostream>
#include <vector>
#include <limits>
#define endl '\n'
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> arr(n);
    while(n--) cin >> arr[n];
    int M = numeric_limits<int>::min();
    int m = numeric_limits<int>::max();
    for(auto iter = arr.begin(); iter < arr.end(); iter++) {
        M = (*iter < M) ? M : *iter;
        m = (*iter > m) ? m : *iter;
    }
    cout << M - m << endl;

    return 0;
}
