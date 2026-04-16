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
    visited[n] = 0;
    int found = 0, m = 0;
    int c = 0;
    while(1){
        if(q.empty()) break;
        pair<int, int> p = q.front();
        q.pop();
        //printf("%d %d %d\n", p.first, p.second, q.size());
        if(visited[p.first] < p.second && visited[p.first] != -1) continue;
        if(p.first == k){
            found = 1;
            m = p.second;
        }
        if(found == 1){
            if(p.second > m) break;
            if(p.first == k) c++;
        }
        visited[p.first] = p.second;
        if(p.first > 0) q.push({p.first - 1, p.second + 1});
        if(p.first < 1000000) q.push({p.first + 1, p.second + 1});
        if(p.first <= 500000) q.push({p.first * 2, p.second + 1});
    }
    cout << m << endl << c << endl;
    delete[] visited;
    return 0;
}
