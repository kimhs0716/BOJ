#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int main(){
    int N, k; cin >> N >> k;
    vector<int> arr(10001);
    while(N--){
        int s; cin >> s;
        arr[s]++;
    }
    int idx = 10000;
    while(k > 0){
        k -= arr[idx];
        idx--;
    }
    cout << idx + 1 << endl;
    return 0;
}