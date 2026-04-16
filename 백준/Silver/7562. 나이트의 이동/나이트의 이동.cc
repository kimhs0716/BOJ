#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef struct {
    int x, y;
    int moves;
} elem;
bool isin(elem item, int w, int h);
int main() {
    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int t;
    cin >> t;
    while(t--){
        queue<elem> q;
        int l;
        scanf("%d", &l);
        bool visited[l][l];
        memset(visited, 0, sizeof(bool) * l * l);
        int x, y, gx, gy;
        scanf("%d %d", &x, &y);
        scanf("%d %d", &gx, &gy);
        elem item = {x, y, 0};
        q.push(item);
        while(item.x != gx || item.y != gy){
            //cout << q.size() << endl;
            item = q.front();
            q.pop();
            visited[item.y][item.x] = 1;
            for(int i = 0; i < 8; i++){
                int nx = item.x + dx[i];
                int ny = item.y + dy[i];
                if(isin({nx, ny, 0}, l, l) && visited[ny][nx] == 0){
                    visited[ny][nx] = 1;
                    q.push({nx, ny, item.moves + 1});
                }
            }
        }
        cout << item.moves << endl;
    }
	return 0;
}
bool isin(elem item, int w, int h){
    return (item.x >= 0 && item.x < w && item.y >= 0 && item.y < h);
}
