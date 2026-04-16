#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n, k;
    int visited[100001] = {0, };
    cin >> n >> k;
    queue<pair<int, int>> q;
    q.push({n, 0});
    while(1){
        pair<int, int> p = q.front();
        q.pop();
        if(p.first == k){
            cout << p.second << endl;
            return 0;
        }
        if(visited[p.first] == 0){
            visited[p.first] = 1;
            if(p.first > 0) q.push({p.first - 1, p.second + 1});
            if(p.first < 100001) q.push({p.first + 1, p.second + 1});
            if(p.first <= 50000) q.push({p.first * 2, p.second + 1});
        }
    }
    return 0;
}
