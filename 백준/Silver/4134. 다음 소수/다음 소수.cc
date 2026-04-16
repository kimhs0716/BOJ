#include <iostream>
#include <cmath>
using namespace std;
bool isprime(long long int);
int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        while(!isprime(n)) n++;
        cout << n << endl;
    }
    return 0;
}
bool isprime(long long int n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    long long int i = 3;
    while(i * i <= n){
        if(n % i == 0) return false;
        i += 2;
    }
    return true;
}
