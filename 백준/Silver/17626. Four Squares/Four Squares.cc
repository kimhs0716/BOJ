#include <iostream>
using namespace std;
int cache[50000];
int rec(int n);
int main(){
    int n;
    cache[0] = 1;
    cin >> n;
    cout << rec(n);
    return 0;
}
int rec(int n){
    if(n == 0) return 0;
    if(cache[n] == 0){
        cache[n] = rec(n - 1) + 1;
        int i = 2;
        while(i * i <= n){
            cache[n] = min(rec(n - i * i) + 1, cache[n]);
            i++;
        }
    }
    return cache[n];
}
