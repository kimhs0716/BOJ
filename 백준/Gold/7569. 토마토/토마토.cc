#include <iostream>
#include <queue>
#define MAX_SIZE 101
using namespace std;
struct tomato {
    int y, x, z;
};
queue<tomato> q;
int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };
int n, m, h, result = 0;
int graph[MAX_SIZE][MAX_SIZE][MAX_SIZE];
bool IsInside(int ny, int nx, int nz) {
    return (0 <= nx && 0 <= ny && nx < m && ny < n && 0 <= nz && nz < h);
}
void bfs(void) {
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int z = q.front().z;
        q.pop();
        for (int i = 0; i < 6; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nz = z + dz[i];
            if (IsInside(ny, nx, nz) == 1 && graph[nz][ny][nx] == 0) {
                graph[nz][ny][nx] = graph[z][y][x] + 1;
                q.push({ ny, nx, nz });
            }
        }
    }
}
int main() {
    cin >> m >> n >> h;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                scanf("%d", &graph[k][i][j]);
                if (graph[k][i][j] == 1) {
                    q.push({ i, j, k });
                }
            }
        }
    }
    bfs();
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                if (graph[k][i][j] == 0) {
                    cout << "-1\n";
                    return 0;
                }
                if (result < graph[k][i][j]) {
                    result = graph[k][i][j];
                }
            }
        }
    }
    cout << result - 1 << endl;
    return 0;
}
