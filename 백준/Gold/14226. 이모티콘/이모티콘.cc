#include <iostream>
#include <queue>
typedef struct {
    int screen;
    int clipboard;
    int depth;
} elem;
using namespace std;
int main(){
    char visited[1101][1101] = {0, };
    visited[1][0] = 1;
    queue<elem> q;
    q.push({1, 0, 0});
    elem item = {-1, };
    int s;
    cin >> s;
    while(item.screen != s){
        item = q.front();
        q.pop();
        if(item.screen != 0 && visited[item.screen - 1][item.clipboard] == 0){
            visited[item.screen - 1][item.clipboard] = 1;
            q.push({item.screen - 1, item.clipboard, item.depth + 1});
        }
        if(item.clipboard != 0 && item.screen + item.clipboard <= 1100 && visited[item.screen + item.clipboard][item.clipboard] == 0){
            visited[item.screen + item.clipboard][item.clipboard] = 1;
            q.push({item.screen + item.clipboard, item.clipboard, item.depth + 1});
        }
        if(item.clipboard != item.screen && visited[item.screen][item.screen] == 0){
            visited[item.screen][item.screen] = 1;
            q.push({item.screen, item.screen, item.depth + 1});
        }
    }
    cout << item.depth << endl;
    return 0;
}
