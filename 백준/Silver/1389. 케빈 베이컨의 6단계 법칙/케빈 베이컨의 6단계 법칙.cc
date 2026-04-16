#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#define MAX_SIZE 101
using namespace std;
vector<vector<int>> adj(MAX_SIZE);
void kevin_bacon(int node);
int kevin_bacon_numbers[MAX_SIZE][MAX_SIZE];
int main(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int res;
    m = INT_MAX;
    for(int i = 1; i <= n; i++){
        kevin_bacon(i);
        int s = 0;
        for(int j = 1; j <= n; j++){
            s += kevin_bacon_numbers[i][j];
            //printf("%d -> %d: %d\n", i, j, kevin_bacon_numbers[i][j]);
        }
        if(m > s) res = i;
        m = min(m, s);
        //printf("%d: %d\n", i, s);
    }
    cout << res << endl;
    return 0;
}
void kevin_bacon(int node){
    int visited[MAX_SIZE] = {0, };
    visited[node] = 1;
    queue<pair<int, int>> q;
    q.push({node, 0});
    while(!q.empty()){
        pair<int, int> next = q.front();
        q.pop();
        kevin_bacon_numbers[node][next.first] = next.second;
        for(int i = 0; i < adj[next.first].size(); i++){
            if(visited[adj[next.first][i]] == 1) continue;
            visited[adj[next.first][i]] = 1;
            q.push({adj[next.first][i], next.second + 1});
        }
        //printf("qsize: %d\n", q.size());
    }
    return;
}
