#include <iostream>
using namespace std;
int cache[1000000];
int fib(int);
int main(){
    int n;
    cin >> n;
    cache[0] = cache[1] = 1;
    cout << fib(n - 1) << endl;
    return 0;
}
int fib(int n){
    if(n == -1) return 0;
    if(cache[n] == 0){
        cache[n] = (fib(n - 1) + fib(n - 2)) % 1000000007;
    }
    return cache[n];
}
