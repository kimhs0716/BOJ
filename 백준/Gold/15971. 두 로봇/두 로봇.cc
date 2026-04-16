#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <fstream>
#define endl '\n'
using namespace std;
typedef pair<int, short> pis;
typedef pair<int, vector<short>> pivs;
int main(){
    int n, r1, r2; cin >> n >> r1 >> r2;
    vector<vector<pis>> adj(n + 1);
    vector<bool> visited(n + 1, 0);
    for(int i = 0; i < n - 1; i++) {
        int a, b; short c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    pivs item;
    item.first = r1;
    visited[r1] = 1;
    queue<pivs> q;
    q.push(item);
    while(!q.empty()) {
        item = q.front();
        q.pop();
        if(item.first == r2) break;
        for(pis i: adj[item.first]) {
            if(visited[i.first]) continue;
            item.first = i.first;
            item.second.push_back(i.second);
            q.push(item);
            visited[i.first] = 1;
            item.second.pop_back();
        }
    }

    short M = 0;
    int s = 0;
    for(int i = 0; i < item.second.size(); i++) {
        M = max<short>(M, item.second[i]);
        s += (int)item.second[i];
    }
    cout << s - (int)M << endl;

    return 0;
}
