#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int n){
    if(n < 2) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    for(int i = 3; i * i <= n; i += 2){
        if(n % i == 0) return 0;
    }
    return 1;
}
int nextP(int n){
    while(!isprime(++n));
    return n;
}
bool foo(int n){
    int i = 2;
    while(i * i <= n){
        int nextPP = nextP(i);
        if(isprime(i) && i * nextPP == n) return 1;
        i = nextPP;
    }
    return 0;
}
int main(){
    int n;
    cin >> n;
    n += foo(n);
    while(!foo(n++));
    cout << --n << endl;
    return 0;
}
