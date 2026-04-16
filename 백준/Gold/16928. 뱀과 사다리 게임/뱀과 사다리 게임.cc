#include <iostream>
#include <queue>
using namespace std;
typedef struct {
    int data, depth;
} elem;
int main(){
    int n, m;
    cin >> n >> m;
    int board[100];
    bool visited[100] = {0, };
    for(int i = 0; i < 100; i++) board[i] = i;
    int a, b;
    for(int i = 0; i < n + m; i++){
        cin >> a >> b;
        a--, b--;
        board[a] = b;
    }
    elem item = {0, 0};
    queue<elem> q;
    q.push(item);
    while(item.data != 99){
        item = q.front();
        //printf("size: %d, data: %d, depth: %d\n", q.size(), item.data, item.depth);
        q.pop();
        for(int i = 1; i <= 6; i++){
            elem next = {item.data + i, item.depth + 1};
            if(next.data >= 100) break;
            while(board[next.data] != next.data){
                next.data = board[next.data];
            }
            if(next.data <= 99 && visited[next.data] == 0){
                visited[next.data] = 1;
                q.push(next);
            }
        }
    }
    cout << item.depth << endl;
    return 0;
}
