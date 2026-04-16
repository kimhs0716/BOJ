#include <iostream>
using namespace std;
int cache[11];
int rec(int n){
    if(cache[n] == 0){
        cache[n] = rec(n - 1) + rec(n - 1) / 20;
        if(n >= 3) cache[n] = max(cache[n], rec(n - 3) + rec(n - 3) / 5);
        if(n >= 5) cache[n] = max(cache[n], rec(n - 5) + rec(n - 5) * 7 / 20);
    }
    return cache[n];
}
int main(){
    int h, y;
    cin >> h >> y;
    cache[0] = h;
    cout << rec(y);
    return 0;
}
