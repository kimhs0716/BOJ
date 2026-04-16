#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int visited[n][m];
    char ch;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            scanf(" %c", &ch);
            arr[i][j] = ch - '0';
            visited[i][j] = 0;
        }
    queue<int> qx;
    queue<int> qy;
    qx.push(0);
    qy.push(0);
    int x = 0, y = 0, depth = 0;
    while(x != m - 1 || y != n - 1){
        depth++;
        int len = qx.size();
        int arrived = 0;
        for(int i = 0; i < len; i++){
            x = qx.front();
            qx.pop();
            y = qy.front();
            qy.pop();
            if(visited[y][x]) continue;
            visited[y][x] = 1;
            if(x == m - 1 && y == n - 1){
                arrived = 1;
                break;
            }
            if(x > 0 && visited[y][x - 1] == 0 && arr[y][x - 1] == 1){
                qx.push(x - 1);
                qy.push(y);
            }
            if(x < m - 1 && visited[y][x + 1] == 0 && arr[y][x + 1] == 1){
                qx.push(x + 1);
                qy.push(y);
            }
            if(y > 0 && visited[y - 1][x] == 0 && arr[y - 1][x] == 1){
                qx.push(x);
                qy.push(y - 1);
            }
            if(y < n - 1 && visited[y + 1][x] == 0 && arr[y + 1][x] == 1){
                qx.push(x);
                qy.push(y + 1);
            }
        }
        if(arrived) break;
    }
    cout << depth;
    return 0;
}
