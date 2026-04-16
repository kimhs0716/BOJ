#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef struct {
    short x, y;
    char distroy;
    int moves;
} elem;
bool isin(elem item, int w, int h);
int main() {
    int w, h, k;
    cin >> h >> w >> k;
    char board[h][w];
    bool visited[h][w][k + 1];
    memset(visited, 0, sizeof(bool) * h * w * (k + 1));
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            scanf(" %c", &board[i][j]);
            board[i][j] -= '0';
        }
    }
    queue<elem> q;
    q.push({0, 0, 0, 0});
    elem item;
    do{
        if(q.empty()){
            cout << "-1\n";
            return 0;
        }
        int nx, ny;
        item = q.front();
        q.pop();
        visited[item.y][item.x][item.distroy] = true;
        for(int i = 0; i < 4; i++){
            nx = item.x + dx[i];
            ny = item.y + dy[i];
            if(isin({nx, ny, 0, 0}, w, h)){
                if(board[ny][nx] == 1){
                    if(item.distroy < k){
                        if(visited[ny][nx][item.distroy + 1] == false){
                            q.push({nx, ny, item.distroy + 1, item.moves + 1});
                            visited[ny][nx][item.distroy + 1] = 1;
                        }
                    }
                }
                else{
                    if(visited[ny][nx][item.distroy] == false){
                        q.push({nx, ny, item.distroy, item.moves + 1});
                        visited[ny][nx][item.distroy] = 1;
                    }
                }
            }
        }
    }while(item.x != w - 1 || item.y != h - 1);
    cout << item.moves + 1 << endl;
	return 0;
}
bool isin(elem item, int w, int h){
    return (item.x >= 0 && item.x < w && item.y >= 0 && item.y < h);
}
