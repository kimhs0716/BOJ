#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef struct {
    vector<int> edges;
    int visited;
} node;
int main() {
    queue<int> q;
    int cnt = 1;
    int n, m, r; cin >> n >> m >> r;
    node **arr = new node*[n + 1];
    for(int i = 1; i <= n; i++) {
        arr[i] = new node;
        arr[i]->visited = 0;
    }
    while(m--){
        int a, b; cin >> a >> b;
        arr[a]->edges.push_back(b);
        arr[b]->edges.push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        sort(arr[i]->edges.begin(), arr[i]->edges.end());
    }
    q.push(r);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(arr[cur]->visited != 0) continue;
        arr[cur]->visited = cnt++;
        for(auto i: arr[cur]->edges) if(arr[i]->visited == 0) q.push(i);
    }
    for(int i = 1; i <= n; i++) {
        cout << arr[i]->visited << endl;
        delete arr[i];
    }
    delete[] arr;

    return 0;
}
