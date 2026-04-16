#include <iostream>
#define MAX_SIZE 64
using namespace std;
char arr[MAX_SIZE][MAX_SIZE + 1];
void dfs(int x, int y, int s);
bool isall(int x, int y, int s);
int n;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%s", arr[i]);
    }
    dfs(0, 0, n);
    cout << endl;
    return 0;
}
void dfs(int x, int y, int s){
    if(s == 1 || isall(x, y, s)){
        cout << arr[y][x];
        return;
    }
    cout << "(";
    dfs(x, y, s / 2);
    dfs(x + s / 2, y, s / 2);
    dfs(x, y + s / 2, s / 2);
    dfs(x + s / 2, y + s / 2, s / 2);
    cout << ")";
}
bool isall(int x, int y, int s){
    for(int i = y; i < y + s; i++){
        for(int j = x; j < x + s; j++){
            if(arr[i][j] != arr[y][x]) return false;
        }
    }
    return true;
}
