#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> adj[20000];
bool visited[20000];
bool __data[20000];
int v, e;
int dfs(int node, bool pre);
int main(){
    int k;
    cin >> k;
    while(k--){
        cin >> v >> e;
        memset(visited, 0, sizeof(bool) * v);
        for(int i = 0; i < v; i++)
            adj[i].clear();
        while(e--){
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a - 1].push_back(b - 1);
            adj[b - 1].push_back(a - 1);
        }
        for(int i = 0; i < v; i++){
            if(visited[i]) continue;
            if(!dfs(i, 0)){
                printf("NO\n");
                goto EXIT;
            }
        }
        printf("YES\n");
        continue;
EXIT:;
    }
    return 0;
}

int dfs(int node, bool pre){
    //printf("node: %d, pre: %d\n", node, pre);
    visited[node] = 1;
    __data[node] = !pre;
    for(auto iter = adj[node].begin(); iter < adj[node].end(); iter++){
        int i = *iter;
        if(visited[i] && pre != __data[i]) return 0;
        if(visited[i] && pre == __data[i]) continue;
        if(!dfs(i, !pre)) return 0;
    }
    return 1;
}
