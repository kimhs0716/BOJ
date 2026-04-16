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
    bool board[h][w];
    bool visited[h][w][k + 1][2];
    memset(visited, 0, sizeof(bool) * h * w * (k + 1) * 2);
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char t;
            scanf(" %c", &t);
            board[i][j] = t - '0';
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
        //cout << q.size() << endl;
        //cout << item.x << ' ' << item.y << ' ' << (int)item.distroy << ' ' << item.moves << endl;
        visited[item.y][item.x][item.distroy][item.moves % 2] = true;
        if(visited[item.y][item.x][item.distroy][(item.moves + 1) % 2] == false){
            q.push({item.x, item.y, item.distroy, item.moves + 1});
            visited[item.y][item.x][item.distroy][(item.moves + 1) % 2] = true;
        }
        for(int i = 0; i < 4; i++){
            nx = item.x + dx[i];
            ny = item.y + dy[i];
            if(isin({nx, ny, 0, 0}, w, h)){
                if(board[ny][nx] == 1){
                    if(item.distroy < k && item.moves % 2 == 0){
                        if(visited[ny][nx][item.distroy + 1][(item.moves + 1) % 2] == false){
                            q.push({nx, ny, item.distroy + 1, item.moves + 1});
                            visited[ny][nx][item.distroy + 1][(item.moves + 1) % 2] = 1;
                        }
                    }
                }
                else{
                    if(visited[ny][nx][item.distroy][(item.moves + 1) % 2] == false){
                        q.push({nx, ny, item.distroy, item.moves + 1});
                        visited[ny][nx][item.distroy][(item.moves + 1) % 2] = 1;
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
