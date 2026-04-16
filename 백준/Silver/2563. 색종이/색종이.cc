#include <iostream>
#include <cstring>
using namespace std;
bool board[100][100];
int main(){
    int t; cin >> t;
    while(t--) {
        int i, j; cin >> i >> j;
        for(int a = 0; a < 10; a++)
            for(int b = 0; b < 10; b++)
                board[i + a][j + b] = 1;
    }
    int cnt = 0;
    for(int i = 0; i < 100; i++) for(int j = 0; j < 100; j++)
        cnt += board[i][j];
    cout << cnt << endl;
    return 0;
}
