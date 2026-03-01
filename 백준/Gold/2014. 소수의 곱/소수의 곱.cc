#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef long long int lld;
int main(){
    int k, n; cin >> k >> n;
    priority_queue<lld, vector<lld>, greater<lld>> q;
    map<lld, bool> check;
    lld *arr = new lld[k];
    for(int i = 0; i < k; i++){
        cin >> arr[i];
    }
    q.push(1);
    lld M = 1;
    check[1] = 1;
    for(int i = 0; i < n; i++){
        lld p = q.top();
        //cout << p << endl;
        q.pop();
        for(int j = 0; j < k; j++){
            if((arr[j] * p < M || q.size() < n) && check[arr[j] * p] == false){
                check[arr[j] * p] = 1;
                q.push(arr[j] * p);
                if(arr[j] * p > M) M = arr[j] * p;
            }
        }
    }
    cout << q.top() << endl;
    return 0;
}
