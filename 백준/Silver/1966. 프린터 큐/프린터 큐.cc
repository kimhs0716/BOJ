#include <iostream>
#include <queue>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, c = 0;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            q.push({i, num});
            pq.push(num);
        }
        while(!q.empty()){
            int idx = q.front().first;
            int pri = q.front().second;
            q.pop();
            if(pq.top() == pri){
                pq.pop();
                c++;
                if(idx == m){
                    cout << c << endl;
                    break;
                }
            }
            else{
                q.push({idx, pri});
            }
        }
    }
    return 0;
}
