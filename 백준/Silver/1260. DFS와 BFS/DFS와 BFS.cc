#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> vec[10101];
vector<int> res_bfs;
vector<int> res_dfs;
bool visited[1010];

void bfs(int tmp)
{
    queue<int> q; q.push(tmp);
    visited[tmp] = true; //tmp번 노드를 방문처리
    while(!q.empty()){
        int x = q.front();
        q.pop();
        res_bfs.push_back(x); // 결과에 저장
        
        for(int i=0; i<vec[x].size(); i++){
            if(!visited[vec[x][i]]){
                q.push(vec[x][i]);
                visited[vec[x][i]] = true;
            }
        }   
    } 
}

void dfs(int tmp)//재귀함수 이용
{
    visited[tmp] = true;
    res_dfs.push_back(tmp);
    for(int i=0; i<vec[tmp].size(); i++){
        if(!visited[vec[tmp][i]]){
            dfs(vec[tmp][i]);
        }
    }
}

int main()
{
    int N, M, V, a, b; cin >> N >> M >> V;
    
    for(int i=1; i<=M; i++){
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a); //양방향 간선생성, 서로 인접노드가 됨
    }
    
    for(int i=1; i<=N; i++){
        sort(vec[i].begin(), vec[i].end());
    }
    
    bfs(V);
    memset(visited, false, sizeof(visited));//방문 노드 초기화
    
    dfs(V);
    
    for(int i=0; i<res_dfs.size(); i++) { //인덱스 0부터 시작 
        cout << res_dfs[i] << " ";
    }
    cout << "\n";
    
    for(int i=0; i<res_bfs.size(); i++) {
        cout << res_bfs[i] << " ";
    }
}