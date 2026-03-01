#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9;

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int main() {
    int r, c; cin>>r>>c;
    vector<vector<int>> arr(r, vector<int>(c));
    for (int i=0; i<r; i++) {
        string s; cin>>s;
        for(int j=0; j<c; j++) 
            arr[i][j] = s[j]-'0';
    }
    vector<vector<array<int, 2>>> vis(r, vector<array<int, 2>>(c));
    vis[0][0][0] = 1;
    queue<array<int, 3>> q;
    q.push({0, 0, 0});
    int time = 0;
    while (q.size()) {
        int sz = q.size();
        time++;
        while (sz--) {
            auto [rr, cc, d] = q.front(); q.pop();
            if (rr==r-1 && cc==c-1) {
                cout<<time<<endl;
                return 0;
            }
            for (int i=0; i<4; i++){
                int nr = rr+dr[i];
                int nc = cc+dc[i];
                if (nr<0 || nr>=r) continue;
                if (nc<0 || nc>=c) continue;
                if (d+arr[nr][nc] >= 2) continue;
                if (vis[nr][nc][d+arr[nr][nc]]) continue;
                vis[nr][nc][d+arr[nr][nc]] = 1;
                q.push({nr, nc, d+arr[nr][nc]});
            }
        }
    }
    cout<<-1<<endl;
    
    return 0;
}