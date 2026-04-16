#include <iostream>
#include <queue>
using namespace std;
typedef long long int lld;
bool visited[50][50];
char board[50][50];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
typedef struct {
    int x, y;
} pos;
typedef struct {
    int pass_through;
    int pass_side;
    pos cur;
} node;
bool operator<(const node &b, const node &a){
    if(a.pass_through < b.pass_through) return 1;
    if(a.pass_through > b.pass_through) return 0;
    return a.pass_side < b.pass_side;
}
bool operator==(const pos &a, const pos &b){
    return a.x == b.x && a.y == b.y;
}
bool operator!=(const pos &a, const pos &b){
    return !(a == b);
}
bool isinside(int x, int y, int n, int m){
    return 0 <= x && x < m && 0 <= y && y < n;
}
int main(){
    priority_queue<node> q;
    pos start, goal;
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf(" %c", &board[i][j]);
            if(board[i][j] == 'S') start = {j, i};
            if(board[i][j] == 'F') goal = {j, i};
        }
    }
    node item = {0, 0, start};
    q.push(item);
    while(1){
        item = q.top();
        q.pop();
        //printf("%d\n", q.size());
        //cout << item.pass_through << " " << item.pass_side << " " << item.cur.x << " " << item.cur.y << endl;
        if(item.cur == goal) break;
        visited[item.cur.y][item.cur.x] = 1;
        for(int i = 0; i < 4; i++){
            bool pushed = 0;
            int nx = item.cur.x + dx[i];
            int ny = item.cur.y + dy[i];
            if(!isinside(nx, ny, n, m)) continue;
            if(visited[ny][nx]) continue;
            if(board[ny][nx] == 'F'){
                cout << item.pass_through << ' ' << item.pass_side << endl;
                return 0;
            }
            if(board[ny][nx] == 'g') {
                if(visited[ny][nx] == 0){
                    q.push({item.pass_through + 1, item.pass_side, nx, ny});
                    visited[ny][nx] = 1;
                    continue;
                }
            }
            for(int j = 0; j < 4; j++){
                int nnx = nx + dx[j];
                int nny = ny + dy[j];
                if(!isinside(nnx, nny, n, m)) continue;
                if(board[nny][nnx] == 'g') {
                    if(visited[ny][nx] == 0){
                        q.push({item.pass_through, item.pass_side + 1, nx, ny});
                        pushed = 1;
                        break;
                    }
                }
            }
            if(pushed == 0) q.push({item.pass_through, item.pass_side, nx, ny});
        }
    }
    cout << item.pass_through << ' ' << item.pass_side << endl;
    return 0;
}
