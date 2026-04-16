#include <iostream>
#define mod 1000000000
int cache[1000000];
using namespace std;
int fib(int n);
int main() {
    cache[1] = 1;
    int n;
    cin >> n;
    int f = fib(n);
    if(f == 0) cout << "0\n";
    else if(f > 0) cout << "1\n";
    else cout << "-1\n";
    cout << abs(f) << endl;
    return 0;
}
int fib(int n){
    if(n == 0) return 0;
    if(n < 0) return fib(-n) * ((n & 1) ? 1 : -1);
    if(cache[n] == 0) cache[n] = (fib(n - 1) + fib(n - 2)) % mod;
    return cache[n];
}
