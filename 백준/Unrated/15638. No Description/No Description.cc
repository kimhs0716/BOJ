#include <iostream>
using namespace std;
bool isprime(int n){
    if(n == 2) return true;
    if(n < 2 || n % 2 == 0) return false;
    int i = 3;
    while(i * i <= n){
        if(n % i == 0) return false;
        i++, i++;
    }
    return true;
}
int main(){
    int n; cin >> n;
    if(isprime(n)) cout << "Yes";
    else cout << "No";
    return 0;
}