#include <iostream>
#include <queue>
typedef long long int lld;
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        priority_queue<lld, vector<lld>, greater<lld>> heap;
        int n;
        cin >> n;
        lld res = 0;
        while(n--){
            int num;
            scanf("%d", &num);
            heap.push(num);
        }
        while(heap.size() != 1){
            lld n1, n2;
            n1 = heap.top();
            heap.pop();
            n2 = heap.top();
            heap.pop();
            heap.push(n1 + n2);
            res += n1 + n2;
        }
        if(res == 0) res = heap.top();
        cout << res << endl;
    }
    return 0;
}
