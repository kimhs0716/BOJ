#include <iostream>
bool visited[100][100];
bool adj[100][100];
int n;
using namespace std;
void dfs(int start, int dst);
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            scanf("%d", &adj[i][j]);
        }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
        if(adj[i][j] && i != j){
            dfs(i, j);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%d ", visited[i][j]);
        printf("\n");
    }
    return 0;
}
void dfs(int start, int dst){
    if(visited[start][dst]) return;
    visited[start][dst] = 1;
    for(int i = 0; i < n; i++){
        if(adj[dst][i])
            dfs(start, i);
    }
    return;
}
