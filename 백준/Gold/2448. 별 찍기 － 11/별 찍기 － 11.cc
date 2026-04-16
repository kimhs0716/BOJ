#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <ctime>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int, int>
#define psi pair<string, int>
#define pll pair<lld, lld>
#define INF 987654321
using namespace std;
typedef long long int lld;
int n;
void rec(char **arr, int x, int y, int level);
int main(){
    //FASTIO;
    cin >> n;
    char **arr = new char*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new char[n * 2];
        for(int j = 0; j < n * 2; j++)
            arr[i][j] = '*';
        arr[i][2 * n - 1] = ' ';
    }
    rec(arr, 0, 0, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n * 2; j++)
            cout << arr[i][j];
        cout << endl;
    }
    return 0;
}
void rec(char **arr, int x, int y, int level){
    for(int k = 0; k < level; k++){
        for(int i = 0; i < level - k - 1; i++){
            arr[y + k][x + i] = arr[y + k][x + 2 * level - i - 2] = ' ';
        }
        arr[y + k][x + level * 2 - 1] = ' ';
    }/*
    for(int k = level / 2; k < level; k++){
        for(int i = 0; i < 2 * level - 2 * k - 1; i++){
            arr[y + k][x + i + k] = ' ';
        }
    }*/
    if(level == 3) {
        arr[y + 1][x + 2] = ' ';
        return;
    }
    rec(arr, x + level / 2, y, level / 2);
    rec(arr, x, y + level / 2, level / 2);
    rec(arr, x + level, y + level / 2, level / 2);
}
