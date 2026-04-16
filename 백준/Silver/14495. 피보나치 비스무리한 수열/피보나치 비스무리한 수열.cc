#include <iostream>
using namespace std;
long long int cache[117];
long long int fib(int);
int main(){
    int n;
    cin >> n;
    cache[0] = cache[1] = cache[2] = 1;
    cout << fib(n - 1) << endl;
    return 0;
}
long long int fib(int n){
    if(cache[n] == 0)
        cache[n] = fib(n - 1) + fib(n - 3);
    return cache[n];
}
