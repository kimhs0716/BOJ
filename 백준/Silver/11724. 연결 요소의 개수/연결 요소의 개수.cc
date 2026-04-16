#include <iostream>
#include <vector>
#define MAX_SIZE 1001
using namespace std;
vector<vector<int>> adj(MAX_SIZE);
int visited[MAX_SIZE];
int n, m;
void dfs(int node);
int main(){
    cin >> n >> m;
    while(m--){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(visited[i] == 1) continue;
        visited[i] = 1;
        cnt++;
        dfs(i);
    }
    cout << cnt << endl;
    return 0;
}
void dfs(int node){
    for(int i = 0; i < adj[node].size(); i++){
        if(visited[adj[node][i]] == 0){
            visited[adj[node][i]] = 1;
            dfs(adj[node][i]);
        }
    }
    return;
}
