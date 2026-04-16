#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int main(){
    int n, k;
    int *visited = new int[1000001];
    memset(visited, -1, sizeof(int) * 1000001);
    cin >> n >> k;

    //first = number, second = depth
    queue<pair<int, int>> q;
    q.push({n, 0});
    pair<int, int> p;
    int m;
    while(1){
        if(q.empty()) break;
        p = q.front();
        q.pop();
        //printf("%d %d %d\n", p.first, p.second, q.size());
        if(visited[p.first] <= p.second && visited[p.first] != -1) continue;
        if(p.first == k){
            m = p.second;
            while(!q.empty()){
                p = q.front();
                q.pop();
                if(p.first != k) continue;
                if(p.second < m) m = p.second;
            }
            break;
        }
        visited[p.first] = p.second;
        if(p.first > 0) q.push({p.first - 1, p.second + 1});
        if(p.first < 1000000) q.push({p.first + 1, p.second + 1});
        if(p.first <= 500000) q.push({p.first * 2, p.second});
    }
    cout << m << endl;
    delete[] visited;
    return 0;
}
