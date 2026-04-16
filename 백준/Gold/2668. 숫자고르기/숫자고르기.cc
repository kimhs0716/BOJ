#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n; cin >> n;
    int *arr = new int[n + 1];
    bool *visited = new bool[n + 1];
    vector<int> selected;
    fill(visited, visited + n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(int node = 1; node <= n; node++) {
        if(visited[node]) continue;
        int cur = node;
        vector<int> dfs;
        int depth = 1;
        while(depth <= 100) {
            if(visited[cur]) break;
            dfs.push_back(cur);
            cur = arr[cur];
            depth++;
            if(cur == node) break;
        }
        if(cur == node) {
            for(auto i: dfs) {
                visited[i] = 1;
                selected.push_back(i);
            }
        }
    }
    cout << selected.size() << endl;
    sort(selected.begin(), selected.end());
    for(auto i: selected) cout << i << endl;

    return 0;
}
