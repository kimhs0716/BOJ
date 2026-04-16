#include <iostream>
#include <queue>
using namespace std;
typedef long long int lld;
typedef struct {
    short x, y;
    char knight;
    int moves;
} elem;
bool isin(elem item, int w, int h);
int main() {
    int k, w, h;
    cin >> k >> w >> h;
    bool board[h][w];
    bool visited[h][w][k + 1] = {1, };
    int kdx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int kdy[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            scanf("%d", &board[i][j]);
        }
    }
    queue<elem> q;
    q.push({0, 0, k, 0});
    visited[0][0][k] = true;
    elem item;
    do{
        if(q.empty()){
            cout << "-1\n";
            return 0;
        }
        int nx, ny;
        item = q.front();
        q.pop();
        if(item.knight > 0){
            for(int i = 0; i < 8; i++){
                nx = item.x + kdx[i];
                ny = item.y + kdy[i];
                if(isin({nx, ny, item.knight - 1, item.moves + 1}, w, h) && board[ny][nx] != 1 && visited[ny][nx][item.knight - 1] == false){
                    q.push({nx, ny, item.knight - 1, item.moves + 1});
                    visited[ny][nx][item.knight - 1] = true;
                }
            }
        }
        for(int i = 0; i < 4; i++){
            nx = item.x + dx[i];
            ny = item.y + dy[i];
            if(isin({nx, ny, item.knight, item.moves + 1}, w, h) && board[ny][nx] != 1 && visited[ny][nx][item.knight] == false){
                q.push({nx, ny, item.knight, item.moves + 1});
                visited[ny][nx][item.knight] = true;
            }
        }
    }while(item.x != w - 1 || item.y != h - 1);
    cout << item.moves << endl;
	return 0;
}
bool isin(elem item, int w, int h){
    return (item.x >= 0 && item.x < w && item.y >= 0 && item.y < h);
}
