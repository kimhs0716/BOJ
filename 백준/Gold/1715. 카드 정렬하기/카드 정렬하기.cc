#include <iostream>
#include <queue>
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int>> heap;
    int n;
    cin >> n;
    int res = 0;
    while(n--){
        int num;
        scanf("%d", &num);
        heap.push(num);
    }
    while(heap.size() != 1){
        int n1, n2;
        n1 = heap.top();
        heap.pop();
        n2 = heap.top();
        heap.pop();
        heap.push(n1 + n2);
        res += n1 + n2;
    }
    cout << res << endl;
    return 0;
}
