#include <bits/stdc++.h>

using namespace std;
int N, M, y, x, ny, nx;
int field[1004][1004];
int visited[1004][1004];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void bfs() {
	queue<pair<int, int>> q;
	q.push({y, x});
	visited[y][x] = 0;
	while(!q.empty()) {
		pair<int, int> npos = q.front(); q.pop();
		for(int i = 0; i < 4; ++i) {
			ny = npos.first + dy[i];
			nx = npos.second  + dx[i];
			if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] >= 0 || field[ny][nx] == 0) continue;
			visited[ny][nx] = visited[npos.first][npos.second] + 1;
			q.push({ny, nx});
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			cin >> field[i][j];
			if(field[i][j] == 2){
				y = i;
				x = j;
			}
		}
	}
	fill(&visited[0][0], &visited[1003][1003], -1);
	bfs();
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			cout << ( (field[i][j] == 0) ? 0 : visited[i][j]) << " ";
		}
		cout << "\n";
	}
}