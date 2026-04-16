#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<pair<int, int>> q;
    int a, b;
    cin >> a >> b;
    q.push({a, 1});
    while(!q.empty()){
        pair<int, int> item = q.front();
        q.pop();
        if(item.first == b){
            cout << item.second << endl;
            return 0;
        }
        if(item.first<= b / 2.0) q.push({item.first * 2, item.second + 1});
        if(item.first <= (b - 1) / 10.0) q.push({item.first * 10 + 1, item.second + 1});
    }
    cout << "-1\n";
    return 0;
}
